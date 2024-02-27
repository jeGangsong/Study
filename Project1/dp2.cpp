#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int memo[10000];
int dong[10000];
int dn;

int getMinCnt(int t)
{
	if (t == 0) {
		return 0;
	}
	if (t < 0) return 21e8;
	if (memo[t] != 0) return memo[t];

	int min = 21e8;
	for (int i = 0; i < dn; i++) {
		int ret = getMinCnt(t - dong[i]);
		if (ret < min) min = ret;
	}

	memo[t] = min + 1;
	return min + 1;
}

int main()
{
	freopen("input.txt", "r", stdin);

	int t, n;
	cin >> t >> dn;
	for (int i = 0; i < dn; i++) cin >> dong[i];

	int ret = getMinCnt(t);

	if (ret >= 21e8) {
		cout << "impossible";
		return 0;
	}

	cout << ret;
	return 0;
}