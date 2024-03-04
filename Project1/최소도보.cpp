#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Info {
	int y;
	int x;
	int cnt;
};

int ax, ay;
int bx, by;
int arr[201][201];
bool visit[201][201];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int dest_sub = 1e9;
int dest_start = 1e9;
int start_sub = 1e9;

void BFS(int u,int v) {
	queue<Info> q;
	q.push({ u,v,0 });

	visit[u][v] = true;

	while (!q.empty()) {
		Info b = q.front();
		q.pop();

		int y = b.y;
		int x = b.x;
		int c = b.cnt;

		if (y == ay && x == ax) {
			start_sub = min(start_sub,c);
		}

		if (y == by && x == bx) {
			dest_sub = min(dest_sub, c);
		}

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx < 0 || ny < 0 || nx >= 201 || ny >= 201) continue;
			if (visit[ny][nx]) continue;
			if (arr[ny][nx] == arr[u][v]) continue;

			visit[ny][nx] = true;
			q.push({ ny,nx,c + 1 });

		}
		
	}

}

void findDest(int u, int v) {
	queue<Info> q;
	q.push({ u,v,0 });

	visit[u][v] = true;

	while (!q.empty()) {
		Info b = q.front();
		q.pop();

		int y = b.y;
		int x = b.x;
		int c = b.cnt;


		if (y == by && x == bx) {
			dest_start = c;
			return;
		}

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx < 0 || ny < 0 || nx >= 201 || ny >= 201) continue;
			if (visit[ny][nx]) continue;

			visit[ny][nx] = true;
			q.push({ ny,nx,c + 1 });

		}

	}
}


int main() {

	freopen("input.txt", "r", stdin);

	cin >> ax >> ay >> bx >> by;

	ax += 100;
	ay += 100;
	bx += 100;
	by += 100;

	vector<Info> subway;

	for (int i = 0; i < 4; i++) {
		int y;
		int x;
		cin >> x >> y;
		subway.push_back({ y+100,x+100 });
	}

	Info leftBottom = subway[0];
	Info leftTop = subway[3];
	Info rightTop = subway[2];
	Info rightBottom = subway[1];

	for (int i = rightBottom.y; i <= leftTop.y; i++) {
		if (i == leftTop.y || i == rightBottom.y) {
			for (int j = leftTop.x; j <= rightBottom.x; j++) {
				arr[i][j] = 1;
			}
		}
		else {
			arr[i][leftTop.x] = 1;
			arr[i][rightBottom.x] = 1;
		}
	}

	for (int i = rightBottom.y; i <= leftTop.y; i++) {
		if (i == leftTop.y || i == rightBottom.y) {
			for (int j = leftTop.x; j <= rightBottom.x; j++) {
				BFS(i, j);
				memset(visit, 0, sizeof(visit));
			}
		}
		else {
			BFS(i, leftTop.x);
			memset(visit, 0, sizeof(visit));
			BFS(i, rightBottom.x);
			memset(visit, 0, sizeof(visit));
		}
	}

	findDest(ay, ax);
	int de = -1;
	int answer = min(dest_sub + start_sub, dest_start);

	cout << answer;
}