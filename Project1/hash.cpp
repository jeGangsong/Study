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
	// ���ĵǾ� ����
	//Binary Search Tree �ڷᱸ���� ����

	//unordered_set<int> us;
	//unordered_map<int, int> umum;
	// ���� �Ǿ� ���� ����
	// Hash Table �ڷᱸ���� ����
	int arr[6] = {1, -4, 2, -5, -1, 9};

	for (int i = 0; i < 6; i++) {
		umum[arr[i]] += 1;
		us.insert(arr[i]);
	}
	int N;
	cin >> N;

	//if (um[n]==0) -> �̷��� ���ϸ� �����ϳ��� �߰���.

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