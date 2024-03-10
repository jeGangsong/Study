#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
pair<int, int> sort_data[100010];
pair<int, int> time[100010];
int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a, t;
		scanf("%d %d", &a, &t);
		sort_data[i] = { a, i };
		time[i] = { a,t };
	}

	int answer = 0, current_finished;
	int next = 1;
	sort(sort_data, sort_data + N);
	priority_queue<int> pq;
	current_finished = sort_data[0].first + time[sort_data[0].second].second;
	while (next < N || !pq.empty())
	{
		while (next < N && sort_data[next].first <= current_finished)
		{
			pq.push(-sort_data[next].second);
			next++;
		}
		if (pq.empty() && next < N)
		{
			current_finished = sort_data[next].first + time[sort_data[next].second].second;
			next++;
		}
		else if (!pq.empty())
		{
			int now = -pq.top();
			answer = max(answer, current_finished - time[now].first);
			current_finished = current_finished + time[now].second;
			pq.pop();
		}
	}

	printf("%d", answer);
	return 0;
}