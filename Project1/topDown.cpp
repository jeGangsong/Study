#include <iostream>

using namespace std;

//팁 1. 메모이제이션 나중에 구현 (다 구현하고 나중에 추가)
//팁 2. 한방에 return 재귀 함수 쓰지 말 것


int memo[1000];

int getResult(int n) {

	if (memo[n]) return memo[n];

	if (n <= 1) return n;

	int a = getResult(n - 2);
	int b = getResult(n - 1);

	memo[n] = a + b;

	return a + b;

}

int main() {

	int ret = getResult(5);

	cout << ret << "\n";

}