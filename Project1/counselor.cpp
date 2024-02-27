#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;


int N;
pair<int, int> arr[1000];
int dp[1000];

int main() {

	freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int day, earn;
		cin >> day >> earn;

		arr[i] = make_pair(day,earn) ;
	}

	int answer = 0;
	int de = -1;

	for (int i = 1; i < N+1; i++) {
		int day = arr[i - 1].first;
		int earn = arr[i - 1].second;

		dp[i] = max(dp[i], dp[i - 1]);
		dp[i + day - 1] = max(dp[i - 1] + earn, dp[i+day-1]);
		//dp[i + day - 1] = max();

		answer = max(answer, dp[i + day - 1]);
		
		
	}

	cout << answer;
}