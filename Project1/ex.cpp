#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring> // c에서 사용하는 char []
#include<queue>
#include <algorithm>
#include <utility>
using namespace std;

struct Print {
	int idx;
	int start;
	int end;

	bool operator<(Print a) const {
		return idx > a.idx;
	}
};
int N, M;
int s, e;
vector<Print> v;
priority_queue<Print> pq;

bool cmp(Print left, Print right) {

	return left.start > right.start;

}
int main() {
	freopen("input.txt", "r", stdin);

	cin >> N;

	int answer = 0;

	for (int i = 0; i < N; i++) {
		int A, T;

		cin >> A >> T;

		v.push_back({ i, A,T });
	}

	sort(v.begin(), v.end(), cmp);

	int old_start = v.back().start;
	int old_endtime = v.back().start+v.back().end;
	v.pop_back();

	while (!v.empty() || !pq.empty()) {

		
		while (!v.empty() && v.back().start <= old_endtime) {
			Print now = v.back();
			v.pop_back();
			pq.push(now);
		}

		if (!v.empty() && pq.empty()) {
			Print now = v.back();
			v.pop_back();
			old_endtime = now.start + now.end;
		}

		else if(!pq.empty()) {
			Print cur = pq.top();
			pq.pop();

			answer = max(answer, old_endtime - cur.start);
			old_endtime += cur.end;
		}
	}
	cout << answer << "\n";
}