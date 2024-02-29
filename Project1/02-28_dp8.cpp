#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <utility>

using namespace std;

int N, W;
pair<int, int> arr[100];
long dp[100][10001];
long answer;

long func(int idx, int length, long weight) {

	if (length == 0) return weight;
	if (idx==N || length < 0) return 0;

	if (dp[idx][length]) {
		if (weight > dp[idx][length]) dp[idx][length] =weight;
		else return dp[idx][length];
	}

	long w = arr[idx].first * arr[idx].second;
	long lcnt = 0;
	long rcnt = 0;
	long cnt = 0;

	cnt=func(idx + 1, length,weight);
	cout << idx << " " << length << " " << weight << "\n";
	cout << "cnt" << "\n";
	lcnt=func(idx + 1, length-arr[idx].first,w+weight );
	cout << idx << " " << length << " " << weight << "\n";
	cout << "lcnt" << "\n";
	rcnt=func(idx+1, length-arr[idx].second, w+weight);
	cout << cnt << " " << lcnt << " " << rcnt << "\n";
	dp[idx][length] = max(lcnt, rcnt);
	dp[idx][length] = max(dp[idx][length], cnt);
	
	return dp[idx][length];
	
}

int main() {

	freopen("input.txt", "r", stdin);

	cin >> N >> W;

	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	cout<< func(0, W, 0)<<"\n";

	int de = -1;

}