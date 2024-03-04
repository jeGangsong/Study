#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct Info {
	int y;
	int x;
	int count;

	bool operator <(Info right) const {
		if (count > right.count) return true;
		if (count < right.count) return false;

		if (y > right.y) return true;
		if (y < right.y) return false;
		if (x > right.x) return true;
		return false;
	}
};
int N;
int arr[21][21];
int visit[21][21];
int characterY = 0;
int characterX = 0;
int level = 2;
int chExp = 0;

int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };

int BFS(int u, int v) {

	priority_queue<Info> q;
	q.push({ u,v,0 });
	visit[u][v] = true;
	while (!q.empty()) {
		Info b = q.top();
		q.pop();
		int y = b.y;
		int x = b.x;
		int c = b.count;

		if (arr[y][x]>=1 && arr[y][x]<=6 && arr[y][x] < level) {
			//cout << y << " " << x << "\n";
			chExp++;
			if (level == chExp) {
				level++;
				chExp = 0;
			}
			arr[y][x] = 9;
			arr[characterY][characterX] =0;
			characterY = y;
			characterX = x;

			return c;
		}

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visit[ny][nx]) continue;
			if (arr[ny][nx] > level) continue;

			visit[ny][nx] = true;
			q.push({ ny,nx,c + 1 });
		}
	}

	return 0;

}

int main() {

	freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				characterX = j;
				characterY = i;
			}
		}
	}

	int answer = 0;

	while (1) {
		int initAnswer = answer;
		memset(visit, 0, sizeof(visit));
		answer += BFS(characterY, characterX);
		
		if (initAnswer == answer) break;
	}

	cout << answer;
	//cout << level << " " << chExp;

}
