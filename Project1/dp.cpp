#include <iostream>

using namespace std;

int memo[1000];

int getResult(int n) {

	if (memo[n]!= 0) return memo[n];

	//메모이제이션 

	if (n <=1) return n;

	int a = getResult(n - 2);
	int b = getResult(n - 1);

	//a+b가 n에 대한 정답 --> 메모한다.

	memo[n] = a + b;

	return a + b;
}

int main() {

	int arr[10] = { 0,1 };


	//Top Down 방식의 DP (귀납적 증명 방식)
	int result = getResult(44);

	cout << result;

}