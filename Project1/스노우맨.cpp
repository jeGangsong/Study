#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
using namespace std;

struct Info {
	int y;
	int x;
	int d;

	bool operator<(Info right) const {
		return d > right.d;
	}

};
int N, M;
int arr[50][50];
int visit[50][50];
int startX, startY;
int destX, destY;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

void dijkstra() {
	
	priority_queue<Info> pq;
	pq.push({ startY,startX ,1});
	

	visit[startY][startX] = 0;

	while (!pq.empty()) {

		Info b = pq.top();
		pq.pop();
		int x = b.x;
		int y = b.y;
		int c = b.d;

		if (arr[y][x] == 3) {
			return;
		}

		for (int d = 0; d < 4; d++) {

			int nx = x + dx[d];
			int ny = y + dy[d];

			if (ny < 0 || nx < 0 || nx >= M || ny >= N) continue;
			int next = 0;
			if (d == 1 || d == 3) {
				if (arr[ny][nx] == 1) next = 1;
				else next = c + 1;
			}
			else {
				if (arr[ny][nx] == 0) continue;
				next = c;
			}

			if (visit[ny][nx] <= next) continue;
			visit[ny][nx] = next;
			pq.push({ ny,nx,visit[ny][nx] });
			
		}
	}
}

int main() {

	freopen("input.txt", "r", stdin);

	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = 1e9;
			cin >> arr[i][j];
			
			if (arr[i][j] == 2) {
				startY = i;
				startX = j;
			}
			else {
				destY = i;
				destX = j;
			}
		}
	}

	dijkstra();
	int de = -1;
	cout << visit[destY][destX] << "\n";


}