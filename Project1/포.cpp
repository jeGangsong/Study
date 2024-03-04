#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Info {
	int y;
	int x;
	int dir;
	int cnt;
	bool check;
	vector<int> pathvec;

	bool operator<(Info right) const {
		return cnt > right.cnt;
	}
};
int arr[51][51];
bool visit[51][51];
int N;
int answer;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void BFS(Info start) {
	priority_queue<Info> q;

	//처음 4방향 모두 검사

	q.push({ start.y, start.x,0,0,0 });
	q.push({ start.y, start.x,1,0,0 });
	q.push({ start.y, start.x,2,0,0 });
	q.push({ start.y, start.x,3,0,0 });

	//arr[start.y][start.x] = 0;
	while (!q.empty()) {
		Info b = q.top();
		q.pop();

		int y = b.y;
		int x = b.x;
		int c = b.cnt;
		int dir = b.dir;
		bool ck = b.check;
		vector<int> v = b.pathvec;
		
		//3번 옮겼으면 패스
		if (c >= 3) continue;

		// 쫄을 하나 넘어 쫄을 만날 때 까지 진행
		while (1) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny < 0 || nx < 0 || nx >= N || ny >= N) break;

			// 빈칸일 경우
			if (arr[ny][nx] == 0) {
				//쫄을 넘었는데 빈칸인 경우는 나머지 방향을 q에 넣음
				if (ck) {
					for (int k = 0; k <= 3; k++) {
						q.push({ ny,nx,(dir + k) % 4,c,0,v });
					}
				}
			}
			// 쫄인 경우
			else if (arr[ny][nx] ==1) {
				// 쫄을 넘었는데 쫄이 나오면
				if (ck) {
					// 방문 한적 없는 쫄이면
					if (visit[ny][nx] == 0) {
						//cout << ny << " " << nx << "\n";
						answer++;
						v.push_back(N * ny + nx);
						for (int k = 0; k <= 3; k++) {
							q.push({ ny,nx,(dir + k) % 4,c,0,v });
						}
						visit[ny][nx] = 1;
						break;
					}
					//방문 한적 있다면?
					else {
						// 과거 쫄을 잡은 경우 path 검사
						// path가 없는데 방문한적 있는 쫄이면 
						// 방문을 해야함. (더 앞으로 갈 수 없음)

						// 방문한적 있으면 없다고 판단해 그대로 진행
						bool flag = false;
						for (int i = 0; i < v.size(); i++) {
							
							int tmpx = v[i] % N;
							int tmpy = v[i] / N;
							
							if (tmpx == nx && tmpy == ny) {
								flag = true;
							}
						}
						if (!flag) {
							v.push_back(N * ny + nx);
							for (int k = 0; k <= 3; k++) {
								q.push({ ny,nx,(dir + k) % 4,c,0,v });
							}
							break;
						}
					}
				}
				// 쫄을 넘지 않았다면 넘는다.
				else {
					c++;
					ck = true;
				}
			}
			x = nx;
			y = ny;
		}

		/*for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";*/

	}
}

int main() {
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {

		answer = 0;
		cin >> N;
		memset(visit, 0, sizeof(visit));

		Info pho = { 0, };
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];

				if (arr[i][j] == 2) {
					pho.y = i;
					pho.x = j;
				}
			}
		}

		BFS(pho);


		cout << "#" << tc << " " << answer << "\n";
	}
}