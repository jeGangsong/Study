#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <cstring>

using namespace std;

int T;
int N;
pair<int,int> arr[1001];
int dp1[100001];

int main() {
	freopen("input.txt", "r", stdin);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {

		cin >> N;
		memset(dp1, 0, sizeof(dp1));
		int sum = 0;
		for (int i = 0; i < N; i++) {
			
			int a, b;
			cin >> a >> b;
			sum += a;
			arr[i] = { a,b };
		}
		
		dp1[sum] = N;

		for (int i = 1; i < N; i++) {
			
			for (int j = 100000; j >= 1; j--) {
				dp1[j] = min(dp1[j], dp1[j - arr[i].first] + arr[i].second);
			}
		}

		int de = -1;

	}


}