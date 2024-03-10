#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
using namespace std;

struct Info {
	int y;
	int x;
	int d;
	int maxJ;

	bool operator<(Info right) const {
		return maxJ > right.maxJ;
	}
};

int N, M;
int arr[50][50];
int visit[50][50];
int startX, startY, destX, destY;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

void Dijkstra() {
	
	priority_queue<Info> pq;
	pq.push({ startY,startX,0,0});

	visit[startY][startX] = 0;
	while (!pq.empty()) {
		Info b = pq.top();
		pq.pop();

		int x = b.x;
		int y = b.y;
		int c = b.d;
		int j = b.maxJ;

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			
			//상 하 이동
			if (d & 1) {
				int max_height = max(c+1, j);
				//땅이 없는 경우
				if (arr[ny][nx] == 0) {
					if (visit[ny][nx] <= max_height) continue;
					visit[ny][nx] = max_height;
					pq.push({ ny,nx,c+1,max_height });
				}
				//땅이 있는 경우
				else {

					if (visit[ny][nx] <= max_height) continue;
					visit[ny][nx] = max_height;
					pq.push({ ny,nx,0,max_height });
				}

			}
			//좌 우 이동
			else {
				if (arr[ny][nx] == 0 || arr[y][x] ==0) continue;
				int max_height = max(c, j);
				if (arr[ny][nx] == 1) {
					
					if (visit[ny][nx] <= max_height) continue;
					visit[ny][nx] = max_height;
					pq.push({ ny,nx,c,max_height });
				}
				else {
					if (visit[ny][nx] <= max_height) continue;
					visit[ny][nx] = max_height;
					pq.push({ ny,nx,c,max_height });
				}
				
			}
			
		}
	}

}

int main() {
	
	freopen("input.txt", "r", stdin);
	cin >> N >> M;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
		{
			visit[i][j] = 1e9;
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				startX = j;
				startY = i;
			}
			else if (arr[i][j] == 3) {
				destX = j;
				destY = i;
			}
		}
	}

	Dijkstra();

	cout << visit[destY][destX] << "\n";

}