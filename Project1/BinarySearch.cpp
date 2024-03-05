#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int K[101];
int X[101];

int Sk[101];
int Sp[101];
int Bk[101];
int Bp[101];
int N, M;

bool check(int num) {

	int money = M;

	for (int i = 0; i < N; i++) {
		
		int cur_money = 21e8;

		int need = K[i] * num - X[i];
		if (need < 0) continue;

		int range = need / Sk[i];
		if (need % Sk[i] > 0) range++;

		for (int r = 0; r <= range; r++) {

			int left_num = need - r * Sk[i];

			int big = (left_num <= 0) ? 0 : left_num / Bk[i];
			if (left_num % Bk[i] > 0) big++;

			cur_money = min(cur_money, r * Sp[i] + big * Bp[i]);
			
		}

		money -= cur_money;
		if (money < 0) return false;
	}

	return true;

}
int main() {

	freopen("input.txt", "r", stdin);

	int answer = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> K[i] >> X[i] >> Sk[i] >> Sp[i] >> Bk[i] >> Bp[i];
	}
	
	int start = 0;
	int end = 100;

	while (start <= end) {

		int mid = (start + end) / 2;

		if (check(mid)) {
			start = mid + 1;
			answer = mid;
		}
		else {
			end = mid - 1;
		}
	}

	cout << answer << "\n";
}