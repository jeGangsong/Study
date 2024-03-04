#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

int arr[300001];
int target[300001];

int main() {

	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {

		int N, K;
		
		cin >> N >> K;

		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		for (int i = 0; i < K; i++) {
			cin >> target[i];
		}

		int start = 0;
		int end = 0;

		int cnt = 0;
		bool flag = false;
		while (end < N) {
			if (target[cnt] == arr[end]) {
				start = end;
				end++;
				cnt++;
			}
			else {
				end++;
			}

			if (cnt == K) {
				flag = true;
				break;
			}
		}

		cout << "#" << tc << " ";
		if (flag) cout << 1 << "\n";
		else cout << 0 << "\n";



	}
}