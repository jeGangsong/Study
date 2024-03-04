#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Info {
	int from;
	int cnt;
	int start;
};
int T;
int N, M, Q;
vector <vector<Info>> graph(100001);
unordered_map<string, int> um;
bool inorder[100001];
bool visit[100001];
int parent[100001];

int find(int idx) {
	if (idx != parent[idx]) return parent[idx] = find(parent[idx]);
	else return parent[idx];
}

void BFS(int start) {

	queue<Info> q;
	q.push({ start,0,start });

	visit[start] = true;

	while (!q.empty()) {
		Info b = q.front();
		q.pop();


		int cur = b.from;
		int c = b.cnt;
		int s = b.start;

		if (s != cur) {
			//cout << cur << "\n";
			string tmp1 = to_string(s) + to_string(cur);
			string tmp2= to_string(cur) + to_string(s);
			if (um.count(tmp1) == 0) {
				um[tmp1] = c;
				um[tmp2] = -c;
			}
			
		}

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].from;
			int sum = c+graph[cur][i].cnt;

			if (visit[next]) continue;

			int curP = find(cur);
			int nextP = find(next);

			if (curP != nextP) {

				parent[nextP] = curP;

			}
			/*string tmp1 = to_string(cur) + to_string(next);
			string tmp2 = to_string(next) + to_string(cur);

			if (um.count(tmp1) == 0) {
				um[tmp1] = graph[cur][i].cnt;
				um[tmp2] = -graph[cur][i].cnt;
			}*/

			visit[next] = true;
			q.push({ next,sum,s });
			//q.push({ next,graph[cur][i].cnt,next });
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {

		cin >> N >> M >> Q;

		int answer = 0;
		um.clear();
		
		for (int i = 1; i < N+1; i++) {
			graph[i].clear();
			parent[i] = i;
		}

		for (int i = 1; i < N+1; i++) {
			inorder[i] = true;
		}
		

		for (int i = 0; i < M; i++) {
			int a, b, c;
			cin >> a >> b >> c;

			graph[b].push_back({ a,c });
			inorder[a] = false;
		}

		for (int i = 1; i < N+1; i++) {
			if (graph[i].size() != 0 && inorder[i] == true) {
				memset(visit, 0, sizeof(visit));
				BFS(i);
			}
		}

		int de = -1;
		for (int i= 0; i < Q; i++) {
			int a, b;
			cin >> a >> b;
			string tmp = to_string(a) + to_string(b);
			if (um.count(tmp) != 0) {
				answer += abs(um[tmp]);
				continue;
			}
			int para = find(a);
			int parb = find(b);

			if (para == parb) {
				string tmp1 = to_string(para) + to_string(a);
				string tmp2 = to_string(para) + to_string(b);

				if (um[tmp1] < 0 && um[tmp2] < 0) {
					answer+= abs(abs(um[tmp1]) + abs(um[tmp2]));
				}
				else
				answer += abs(abs(um[tmp1]) - abs(um[tmp2]));
			}
			else {
				answer -= 1;
			}

		}

		cout << "#" << tc << " " << answer << "\n";
	}
}