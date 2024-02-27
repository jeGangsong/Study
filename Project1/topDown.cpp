#include <iostream>

using namespace std;

//�� 1. �޸������̼� ���߿� ���� (�� �����ϰ� ���߿� �߰�)
//�� 2. �ѹ濡 return ��� �Լ� ���� �� ��


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