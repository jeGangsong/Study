#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

struct Point {
	int y;
	int x;
	int dir;
	int count;
};
int answer;

int visit[101][101];
int N;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int startX, startY, startdir;
vector<vector<pair<int, int>>> wormhall(6);

void init() {
	

	for (int i = 0; i < 6; i++) {
		wormhall[i].clear();
	}
	answer = 0;
	startX = -1;
	startY = -1;

}

void input(int arr[][101]) {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			visit[i][j] = 0;

			if (arr[i][j] >= 6) {
				wormhall[arr[i][j]-6].push_back({ i,j });
			}
		}
	}
	int de = -1;
}

void BFS(int arr[][101], int u, int v, int dir) {

	queue<Point> q;
	q.push({ u,v,dir,0 });
	
	while (!q.empty()) {

		Point b = q.front();
		q.pop();

		int y = b.y;
		int x = b.x;
		int d = b.dir;
		int c = b.count;
		//cout << y << " " << x << " " << d << "\n";
		if (y == startY && x == startX) {
			if (visit[y][x] == 0) visit[y][x] = 1;
			else {
				answer = max(answer, c);
				return;
			}
		}

		int ny = y + dy[d];
		int nx = x + dx[d];

		if (ny < 0 || nx < 0 || nx >= N || ny >= N) {
			answer = max(answer, c * 2 + 1);
			return;
		}
		if (visit[ny][nx]) {
			answer = max(answer, c * 2 + 1);
			return;
		}
		if (arr[ny][nx] == -1) {
			answer = max(answer, c);
			return;
		}

		int caseone = arr[ny][nx];
		switch (caseone) {
		case 0:
			visit[ny][nx] = true;
			q.push({ ny,nx,d,c });
		case 1:
			if (d == 1 || d == 2) {
				visit[ny][nx] = true;
				q.push({ ny,nx,(d + 2) % 4,c + 1 });
				continue;
			}
			answer = max(answer, c * 2 + 1);
			return;
		case 2:
			if (d == 0 || d == 2) {
				visit[ny][nx] = true;
				q.push({ ny,nx,(d + 3) % 4,c + 1 });
				continue;
			}
			answer = max(answer, c * 2 + 1);
			return;
		case 3:
			if (d == 0 || d == 3) {
				visit[ny][nx] = true;
				q.push({ ny,nx,(d + 2) % 4,c + 1 });
				continue;
			}
			answer = max(answer, c * 2 + 1);
			return;
		case 4:
			if (d == 3 || d == 1) {
				visit[ny][nx] = true;
				q.push({ ny,nx,(d + 1) % 4,c + 1 });
				continue;
			}
			answer = max(answer, c * 2 + 1);
			return;
		case 5:
			{
				visit[ny][nx] = true;
				answer = max(answer, c * 2 + 1);
				return;
			}
		default:
			visit[ny][nx] = true;
			for (int i = 0; i < wormhall[caseone - 6].size(); i++) {
				pair<int, int> worm = wormhall[caseone - 6][i];

				if (worm.first == ny && worm.second == nx) {
					pair<int, int> tmp = wormhall[caseone - 6][!i];
					visit[tmp.first][tmp.second] = true;
					q.push({ tmp.first,tmp.second,d,c });
					break;
				}
			}
		}
		
		/*else if (arr[ny][nx] == 0) {
			visit[ny][nx] = true;
			q.push({ ny,nx,d,c });
		}
		else if (arr[ny][nx] == 1) {
			if (d == 1 || d == 2) {
				visit[ny][nx] = true;
				q.push({ ny,nx,(d + 2) % 4,c + 1 });
				continue;
			}
			answer = max(answer, c * 2 + 1);
			return;
		}
		else if (arr[ny][nx] == 2) {
			if (d == 0 || d == 2) {
				visit[ny][nx] = true;
				q.push({ ny,nx,(d + 3) % 4,c + 1 });
				continue;
			}
			answer = max(answer, c * 2 + 1);
			return;
		}
		else if (arr[ny][nx] == 3) {
			if (d == 0 || d == 3) {
				visit[ny][nx] = true;
				q.push({ ny,nx,(d + 2) % 4,c + 1 });
				continue;
			}
			answer = max(answer, c * 2 + 1);
			return;
			
		}
		else if (arr[ny][nx] == 4) {
			if (d == 3 || d == 1) {
				visit[ny][nx] = true;
				q.push({ ny,nx,(d + 1) % 4,c + 1 });
				continue;
			}
			answer = max(answer, c * 2 + 1);
			return;
		}
		else if (arr[ny][nx] == 5) {
			visit[ny][nx] = true;
			answer = max(answer, c * 2 + 1);
			return;
		}
		else if (arr[ny][nx] >= 6) {
			visit[ny][nx] = true;
			for (int i = 0; i < wormhall[arr[ny][nx] - 6].size(); i++) {
				pair<int, int> worm = wormhall[arr[ny][nx] - 6][i];

				if (worm.first == ny && worm.second == nx) {
					pair<int, int> tmp = wormhall[arr[ny][nx] - 6][!i];
					visit[tmp.first][tmp.second] = true;
					q.push({ tmp.first,tmp.second,d,c });
					break;
				}
			}
		}*/

	}
}

void solve(int arr[][101]) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			startY = i;
			startX = j;
			for (int d = 0; d < 4; d++) {
				memset(visit, 0, sizeof(visit));
				if (arr[i][j] == 0) {
					BFS(arr,i, j, d);
				}
				else break;
			}
		}
		/*if (i == 0 || i == N - 1) {
			for (int j = 0; j < N; j++) {
				startY = i;
				startX = j;
				for (int d = 0; d < 4; d++) {
					if (arr[i][j] == 0) BFS(i, j, d);
					else break;
				}
			}
		}
		else {
			if (i == 4) int de = -1;
			for (int j = 0; j < N; j += N - 1) {
				startY= i;
				startX = j;
				for (int d = 0; d < 4; d++) {
					if (arr[i][j] == 0) BFS(i, j, d);
					else break;
				}
			}
		}*/
	}

}
int main() {

	freopen("input.txt", "r", stdin);
	int T;

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {

		init();

		int arr[101][101] = { 0 };

		cin >> N;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		int de = -1;
		//input(arr);

		solve(arr);


		cout << "#" << tc << " " << answer << "\n";
	}
}