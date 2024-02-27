#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int main() {

	set<int> us;
	map<int, int> umum;
	// 정렬되어 있음
	//Binary Search Tree 자료구조로 구현

	//unordered_set<int> us;
	//unordered_map<int, int> umum;
	// 정렬 되어 있지 않음
	// Hash Table 자료구조로 구현
	int arr[6] = {1, -4, 2, -5, -1, 9};

	for (int i = 0; i < 6; i++) {
		umum[arr[i]] += 1;
		us.insert(arr[i]);
	}
	int N;
	cin >> N;

	//if (um[n]==0) -> 이렇게 비교하면 원소하나가 추가됌.

	if (umum.count(N)!=0) {
		cout << "O" << "\n";
	}
	else {
		cout << "X" << "\n";
	}

	if (us.count(N) != 0) {
		cout << "O" << "\n";
	}
	else {
		cout << "X" << "\n";
	}
}