#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <queue>
#include <math.h>
#include <vector>

using namespace std;

struct Info {
	int y;
	int x;
};

int T;
int N, M;
bool visit[500][500];
int map[500][500];
int dist[500][500];
vector<Info> PointVec;
int max_dist;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int answer;

bool BFS(int mid) {

	
	memset(visit, 0, sizeof(visit));

	int cnt = 0;
	queue<Info> q;
	int u = PointVec[0].y;
	int v = PointVec[0].x;
	visit[u][v] = true;
	q.push({ u,v});

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;

		q.pop();

		if (map[y][x] == 1) {
			cnt++;
		}

		if (cnt == PointVec.size()) return true;

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (ny < 0 || nx < 0 || nx >= M || ny >= N) continue;
			if (visit[ny][nx]) continue;

			int next = abs(dist[y][x] - dist[ny][nx]);

			if (next <= mid) {
				visit[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
	}

	/*for (int i = 0; i < PointVec.size(); i++) {
		if (visit[PointVec[i].y][PointVec[i].x] == false)
			return false;
	}*/
	return false;
}

int bs() {
	
	int tmp = 0;
	int start = 0;
	int end = max_dist;


	while (start <= end) {

		int mid = (start + end) / 2;

		if (BFS(mid)) {
			end = mid - 1;
			tmp = mid;
		}
		else {
			start = mid + 1;
		}
	}

	return tmp;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> dist[i][j];
			if (max_dist < dist[i][j]) {
				max_dist = dist[i][j];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				PointVec.push_back({ i,j });
			}
		}
	}

	

	cout << bs();



}