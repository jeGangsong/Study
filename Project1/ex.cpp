#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int arr[1000][1000];
int dp[1000][1000];
int path[1000][1000];
int dx[3] = {0, -1,0 };
int dy[3] = {0, 0,-1 };
int N;
vector<pair<int, int>> v;

int ydir[2] = { 0,1 };
int xdir[2] = { 1,0 };

int func(int y, int x) {

	if (y >= N || x >= N) return 21e8;
	if (y == N - 1 && x == N - 1) return 0;

	if (dp[y][x] != 0) return dp[y][x];

	int minval = 21e8;

	for (int i = 0; i < 2; i++) {
		int temp = func(y + ydir[i], x + xdir[i]);
		if (temp < minval) {
			minval = temp;
			path[y][x] = i;
		}
	}
	dp[y][x] = minval+arr[y][x];
	return dp[y][x];

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	//Bottom-Up

	//dp[0][0] = arr[0][0];

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == 0 && j == 0) continue;
			else if(i==0) {
				dp[i][j] = dp[i][j - 1]+arr[i][j];
				path[i][j] = 1; // аб
			}
			else if (j == 0) {
				dp[i][j] = dp[i - 1][j]+arr[i][j];
				path[i][j] = 2; // ю╖
			}
			else {
				if (dp[i - 1][j] + arr[i][j] <= dp[i][j - 1] + arr[i][j]) {
					dp[i][j] = dp[i - 1][j] + arr[i][j];
					path[i][j] = 2; //ю╖
				}
				else {
					dp[i][j] = dp[i][j-1] + arr[i][j];
					path[i][j] = 1; //аб
				}
			}
		}
	}*/

	/*int y = N - 1;
	int x = N - 1;

	v.push_back({ N - 1,N - 1 });

	while (y != 0 || x != 0) {
		int d = path[y][x];

		int nx = x + dx[d];
		int ny = y + dy[d];

		v.push_back({ ny,nx });
		y = ny;
		x = nx;
	}

	cout << dp[N - 1][N - 1] << "\n";

	while (!v.empty()) {
		cout << v.back().first << "," << v.back().second << "\n";
		v.pop_back();
	}*/

	//Top-Down
	int ans = func(0, 0);
	cout << ans << "\n";

	int y = 0;
	int x = 0;

	v.push_back({ N - 1,N - 1 });

	while (y != N-1 || x != N-1) {
		int d = path[y][x];

		cout << y << "," << x << "\n";

		int nx = x + xdir[d];
		int ny = y + ydir[d];

		y = ny;
		x = nx;
	}

	cout << y << "," << x << "\n";
	

}
