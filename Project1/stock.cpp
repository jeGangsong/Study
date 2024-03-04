#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int T;
int arr[15][16];
int L, N;
int Ma, Ms;
int dp[16];

int main() {

	freopen("input.txt", "r", stdin);
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> Ma >> Ms;
		cin >> N >> L;

		for (int i = 0; i < 16; i++) {
			dp[i] = 0;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < L+1; j++) {
				cin >> arr[i][j];
			}
		}

		
		int money = Ma;
		int maxProfit = 0;
		int maxIdx = 0;
		int stockNum = 0;

		for (int i = 0; i < N; i++) {
			
			stockNum = money / arr[i][0];
			int restMoney = money % arr[i][0];
			if (arr[i][1] * stockNum+restMoney > money) {
				if (maxProfit < arr[i][1] * stockNum+ restMoney - money) {
					maxProfit = arr[i][1] * stockNum+ restMoney - money;
					maxIdx = i;
				}
			}
		}
		dp[0] = maxProfit;
		for(int i = 1; i < L; i++) {
			maxProfit = 0;
			money += Ms;
			int initMoney = money;
			for (int j = 0; j < N; j++) {
				stockNum = money / arr[j][i];
				int restMoney = money % arr[j][i];
				if (arr[j][i+1] * stockNum+restMoney > money) {
					if (maxProfit < arr[j][i + 1] * stockNum+restMoney - money) {
						maxProfit = arr[j][i + 1] * stockNum+restMoney - money;
						maxIdx = j;
					}
				}
			}

			cout << maxIdx << "\n";
			dp[i] = dp[i - 1] + maxProfit;
			//cout << maxProfit << "\n";
			money = initMoney + maxProfit;
			
		}

		int de = -1;

		cout << "#" << tc << " " << dp[L - 1] << "\n";;

	}


}