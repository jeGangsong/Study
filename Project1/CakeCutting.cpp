#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N;
char arr[200001];

int main() {
	freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int range = N / 2;
	int cur = N;
	int idx = 0;
	int answer = 0;
	int s = 0;
	int k = 0;
	for (int i = 0; i < range; i++) {
		if (arr[i] == 's') s++;
		if (arr[i] == 'k') k++;
	}

	if (s == range / 2 && k == range / 2) {
		idx = range;
		if (idx + range < N-1) answer = idx + range;
		
		if (answer != 0) {
			cout << 2 << "\n";
			cout << idx << " " << answer << "\n";
		}
		else {
			cout << 1 << "\n";
			cout << idx << "\n";
		}
		exit(0);
	}

	for (int i = 1; i <= range; i++) {

		if (arr[i - 1] == 's') s--;
		else if (arr[i - 1] == 'k') k--;

		if (arr[(i + range-1) % N] == 's') s++;
		if (arr[(i + range-1) % N] == 'k') k++;

		if (s == range / 2 && k == range / 2) {
			idx = i % N;
			if (idx + range < N-1) answer = idx + range;
			break;
		}

	}

	if (answer != 0) {
		cout << 2 << "\n";
		cout << idx << " " << answer << "\n";
	}
	else {
		cout << 1 << "\n";
		cout << idx << "\n";
	}
	
} 