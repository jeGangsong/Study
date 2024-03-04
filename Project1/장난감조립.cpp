#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct Info {
	int from;
	int cnt;
	int total;
};

int answer;
vector<vector<Info>> graph(101);
int T, N;
bool basicNum[101];
bool visit[101];
int DAT[101][101];

void BFS(int target) {
	queue<Info> q;
	q.push({ target,1 });

	visit[target] = true;

	while (!q.empty()) {
		Info b = q.front();
		q.pop();

		int cur = b.from;
		int sum = b.cnt;

		if (graph[cur].empty()) {
			DAT[target][cur] += sum;
			continue;
		}

		for (int i = 0; i<graph[cur].size(); i++) {
			int next = graph[cur][i].from;
			int need = sum*graph[cur][i].cnt;

			q.push({ next,need,0 });
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);


	cin >> N >> T;

	memset(basicNum, 1, sizeof(basicNum));

	for (int i = 0; i < T; i++) {
		int a, b, c;

		cin >> a >> b >> c;

		graph[a].push_back({ b,c });
		basicNum[a] = false;

	}
	int de1 = -1;

	BFS(N);

	for (int i = 0; i < N; i++) {
		if (DAT[N][i]) {
			cout << i << " " << DAT[N][i] << "\n";
		}
	}
}
