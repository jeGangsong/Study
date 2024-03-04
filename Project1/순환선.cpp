#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

int N;
int arr[21];
int via[21];
int T;
vector<int> path;
vector<pair<int, int>> v;
int answer;

//int calc(int start,int end) {
//
//	int sum = 0;
//	int selectstart = start;
//	int selectend = end;
//	for (int i = 0; i < v.size(); i++) {
//		if (v[i].first >= start && v[i].second <= end) {
//			sum += (arr[v[i].first] + arr[v[i].second]) * (arr[v[i].first] + arr[v[i].second]);
//			break;
//		}
//	}
//
//	while(start)
//
//
//
//}

void solve(int idx, int start) {

	
	if (idx == 2) {
		v.push_back({ path[0],path[1] });
		
		return;
	}
	

	for (int i = start; i < N; i++) {

		if (via[i]) continue;

		via[(i + N - 1) % N] +=1;
		via[i] +=1;
		via[(i + 1) % N] +=1;
		path.push_back(i);
		solve(idx + 1,i+1);
		path.pop_back();
		via[(i + N - 1) % N] -= 1;
		via[i] -=1;
		via[(i + 1) % N] -=1;
	}


}

int main() {

	freopen("input.txt", "r", stdin);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {

		cin >> N;
		v.clear();

		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		solve(0,0);
		
		answer = 0;
		memset(via, 0, sizeof(via));

		for (int i = 0; i < v.size(); i++) {
			int start = v[i].first;
			int end = v[i].second;

			via[(start + N - 1) % N] = 1;
			via[(start + 1) % N] = 1;
			via[start] = 1;
			via[(end + N - 1) % N] = 1;
			via[end] = 1;
			via[(end + 1) % N] = 1;
			
			for (int j = i+1; j < v.size(); j++) {

				if (i == j) continue;
				int sum = (arr[start] + arr[end]) * (arr[start] + arr[end]);

				int s = v[j].first;
				int e = v[j].second;

				if (via[s]) continue;
				if (via[e]) continue;

				if (s > start && s<end && e>start && e < end) {
					
					sum += (arr[s] + arr[e]) * (arr[s] + arr[e]);
					if (sum > answer) answer = sum;
				}
				else if (s>start && s>end && e > start && e > end) {

					sum += (arr[s] + arr[e]) * (arr[s] + arr[e]);
					if (sum > answer) answer = sum;
				}
				
				
				
				

			}
			via[(start + N - 1) % N] = 0;
			via[(start + 1) % N] = 0;
			via[start] = 0;
			via[(end + N - 1) % N] = 0;
			via[end] = 0;
			via[(end + 1) % N] = 0;
		}
		
		cout << "#" << tc << " " << answer << "\n";
	}
}