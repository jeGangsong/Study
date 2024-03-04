#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

struct Info {
	int y;
	int x;
	int dir;
};

int T;
int N, M, K;
int arr[501][501];
bool visit[501][501];
vector<vector<Info>> vec(10001);

int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };

void BFS(int u, int v) {
	queue<Info> q;

	q.push({ u,v,0});
	q.push({ u,v,1 });
	q.push({ u,v,2 });
	q.push({ u,v,3 });

	int cnt = 0;
	visit[u][v] = true;
	while (!q.empty()) {

		Info b = q.front();
		q.pop();

		int x = b.x;
		int y = b.y;
		int d = b.dir;

		while (1) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N) break;

			if (arr[u][v] == arr[ny][nx]) {
				if (visit[ny][nx]) {
					break;
				}
				visit[ny][nx] = true;
				q.push({ ny,nx,(d + 1) % 4 });
				q.push({ ny,nx,(d + 3) % 4 });
			}

			x = nx;
			y = ny;
		}
	}

}

int main() {
	freopen("input.txt", "r", stdin);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {

		int answer = 0;
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < K; i++) {
			vec[i].clear();
		}

		cin >> N >> M >> K;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> arr[i][j];
				vec[arr[i][j]].push_back({ i,j });
			}
		}

		int targetNum = 1;
		while (targetNum <= K) {

			for (int i = 0; i < vec[targetNum].size(); i++) {
				Info b = vec[targetNum][i];

				int y = b.y;
				int x = b.x;

				if (visit[y][x] == 0) {
					BFS(y, x);
					answer++;
				}
			}
			targetNum++;
		}

		cout << answer << "\n";
	}
}