#include <iostream>

using namespace std;

int memo[1000];

int getResult(int n) {

	if (memo[n]!= 0) return memo[n];

	//�޸������̼� 

	if (n <=1) return n;

	int a = getResult(n - 2);
	int b = getResult(n - 1);

	//a+b�� n�� ���� ���� --> �޸��Ѵ�.

	memo[n] = a + b;

	return a + b;
}

int main() {

	int arr[10] = { 0,1 };


	//Top Down ����� DP (�ͳ��� ���� ���)
	int result = getResult(44);

	cout << result;

}