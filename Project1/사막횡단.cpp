#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;

struct Info {
	int pos;
	int cnt;
};
int N, M, K;
vector<Info> store;
long long minHP = 2e18;
int storeCount[200001];
int answerStore[200001];
int tempStore[200001];

bool check(int limit) {

	int water = N;
	long long HP = 0;
	int location = 0;
	int idx = 0;

	while (1) {
		
		/*if (limit == 5) {
			cout << "location : " << location << "\n";
			cout << "water : " << water << "\n";
			cout << "HP : " << HP << "\n";
		}*/
		
		if (location == M) {
			if (minHP > HP) {
				minHP = HP;
				for (int i = 0; i < K; i++) {
					storeCount[i] = tempStore[i];
				}
			}	
			return true;
		}

		if (idx<K && location == store[idx].pos) {
			if (limit > water) {
				int tmp = 0;
				if (idx + 1 < K && store[idx+1].pos-location > water) {
					tmp = min(limit - water, store[idx + 1].pos - location - water);
				}
				else {
					tmp = min(limit - water, M - location - water);
				}
				
				//cout << " tmp : " << tmp << "\n";
				if (tmp > store[idx].cnt) return false;
				
				water += tmp;
				tempStore[idx] = tmp;
				idx++;
			}
			else {
				tempStore[idx] = 0;
				idx++;
			}
		}
		
		HP += water;
		water--;
		if (water < 0) return false;
		location++;

		
	}

}

int main() {
	
	freopen("input.txt", "r", stdin);
	
	cin >> N >> M >> K;

	for (int i = 0; i < K; i++) {
		int p, c;
		cin >> p >> c;

		store.push_back({ p,c });
	}

	int answer = 0;
	int start = 1;
	int end = max(N,M);
	

	while (start <= end) {
		int mid = (start + end) / 2;

		//cout << "mid : " << mid << "\n";
		if (check(mid)) {
			
			end = mid - 1;
			answer = mid;
			for (int i = 0; i < K; i++) {
				answerStore[i] = storeCount[i];
			}
		}
		else {
			start = mid + 1;
		}
	}
	int de = -1;
	for (int i = 0; i<store.size(); i++) {
		
		cout << store[i].pos << " " << answerStore[i] <<"\n";
	}

	
}