#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <utility>

using namespace std;

struct Color {
	int r;
	int g;
	int b;

};

int N;
int destR, destG, destB;
Color arr[101];
int dp[101][101][101];

double answer = 1e9;

int main() {

	freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++)
		{
			for (int k = 0; k < 101; k++)
			{
				dp[i][j][k] = 1e9;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		int R, G, B;
		cin >> R >> G >> B;

		arr[i] = { R,G,B };
	}

	cin >> destR >> destG >> destB;

	Color dest = { destR, destG, destB };

	for (int i = 0; i < N; i++) {

		Color tmp = arr[i];

		int r = tmp.r;
		int g = tmp.g;
		int b = tmp.b;

		dp[r][g][b] = 1;
		for (int j = 100; j > r; j--) {
			for (int k = 100; k > g; k--) {
				for (int q = 100; q > b; q--)
				{
					dp[j][k][q] = min(dp[j][k][q], dp[j - r][k - g][q - b] + 1);
				}
			}

		}
	}

	int de = -1;

	if (dp[destR][destG][destB] == 1e9) cout << -1 << "\n";

	else cout << dp[destR][destG][destB] << "\n";



}