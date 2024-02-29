#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <deque>
#include <unordered_map>
#include <string>


using namespace std;

int N, K;
int arr[12];
int path[9];
bool via[12];
map<string, int> p;
int number[9] = { 1,2,3,4,5,6,7,8,9 };

void select(int num, int idx, int start) {


	if (idx == num) {
		int sum = 0;
		int digit = 1;
		for (int i = idx-1; i > -1; i--) {
			sum += path[i] * digit;
			digit *= 10;
		}

		p[to_string(sum)] = 1;
	}

	for (int i = start; i < N; i++) {
		int temp = number[i];

		if (via[temp]) continue;
		via[temp] = true;
		path[idx] = temp;
		select(num, idx + 1, i + 1);
		via[temp] = false;
	}

	
}

int main() {
	freopen("input.txt", "r", stdin);

	cin >> N >> K;

	map<int, int> m;

	for (int i = 0; i < K; i++) {
		cin >> arr[i];

		int temp = arr[i];
	}

	for(int i=1; i<=N; i++){
		select(i, 0, 0);
	}

	map <string, int> copymap(p);

	for (int i = 0; i < K; i++) {
		deque<char> deq;
		int temp = arr[i];

		while (temp) {
			deq.push_front((temp % 10)+'0');
			temp /= 10;
		}
		int de1 = 1;
		for (auto item : p) {
			map<char, int> tmp;
			string target = item.first;
			for (int i = 0; i < target.length(); i++) {
				tmp[target[i]] = 1;
			}

			bool flag = true;
			for (auto e : deq) {
				if (tmp.count(e) == 0) {
					flag = false;
					break;
				}
			}
			if (flag) copymap.erase(target);

			
		}
	}

	cout << copymap.size();


}