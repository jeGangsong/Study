#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct Info {
	int y;
	int x;
};

int N, M;
int arr[102][102];
int copyarr[102][102];
bool visit[102][102];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
vector<vector<Info>> v(20000);

bool BFS() {
	
	queue<Info> q;
	q.push({ 1,1 });
	arr[1][1] = 1;

	for (int i = 1; i < N+1; i++) {
		for (int j = 1; j < N+1; j++) {
			copyarr[i][j] = arr[i][j];
		}
	}

	while (!q.empty()) {
		Info b = q.front();
		q.pop();
		int y = b.y;
		int x = b.x;

		vector<Info> room = v[y * (N+1) + x];

		for (int i = 0; i < room.size(); i++) {
			int tmpy = room[i].y;
			int tmpx = room[i].x;

			arr[tmpy][tmpx] = 1;
		}

		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (ny < 1 || nx < 1 || nx >= N+1 || ny >= N+1) continue;
			if (visit[ny][nx]) continue;
			if (arr[ny][nx] == 0) continue;
			visit[ny][nx] = true;
			q.push({ ny,nx });

		}
	}

	for (int i = 1; i < N+1; i++) {
		for (int j = 1; j < N+1; j++) {
			if (copyarr[i][j] != arr[i][j]) {
				return true;
			}
		}
	}

	return false;

}

int main() {

	freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int y1, x1, y2, x2;

		cin >> y1 >> x1 >> y2 >> x2;

		int temp = y1 * (N+1) + x1;
		v[temp].push_back({ y2,x2 });
	}


	while (BFS()) {
		memset(visit, 0, sizeof(visit));
	}

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j]) answer++;
		}
	}

	cout << answer;

}