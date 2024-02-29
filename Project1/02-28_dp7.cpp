#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int arr[51][10];
long long dp[51][1001];
int N, M, H;

long func(int idx, int height) {
	if (height == 0) return 1;
	if (idx >= N + 1 || height < 0) {
		return 0;
	}

	if (dp[idx][height]) return dp[idx][height];

	long cnt = 0;

	cnt = func(idx + 1, height); //¼³Ä¡ x

	for (int i = 0; i < M; i++) {
		if (arr[idx][i] == -1) continue;
		cnt += func(idx + 1, height - arr[idx][i]);
	}

	dp[idx][height] = cnt;
	return cnt;
}

int main() {

	freopen("input.txt", "r", stdin);



	cin >> N >> M >> H;


	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	//Bottom-up

	/*for (int i = 0; i <= N; i++) dp[i][0] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= H; j++) {
			for (int k = 0; k < M; k++) {
				int temp = arr[i][k];
				if (temp == -1) continue;
				if ((j - temp) >= 0) {
					dp[i][j] += dp[i - 1][j - temp];
				}
			}
			dp[i][j] += dp[i - 1][j];
		}
	}

	cout << dp[N][H];*/

	cout << func(1, H);
}

