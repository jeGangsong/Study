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

	//ó�� 4���� ��� �˻�

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
		
		//3�� �Ű����� �н�
		if (c >= 3) continue;

		// ���� �ϳ� �Ѿ� ���� ���� �� ���� ����
		while (1) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny < 0 || nx < 0 || nx >= N || ny >= N) break;

			// ��ĭ�� ���
			if (arr[ny][nx] == 0) {
				//���� �Ѿ��µ� ��ĭ�� ���� ������ ������ q�� ����
				if (ck) {
					for (int k = 0; k <= 3; k++) {
						q.push({ ny,nx,(dir + k) % 4,c,0,v });
					}
				}
			}
			// ���� ���
			else if (arr[ny][nx] ==1) {
				// ���� �Ѿ��µ� ���� ������
				if (ck) {
					// �湮 ���� ���� ���̸�
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
					//�湮 ���� �ִٸ�?
					else {
						// ���� ���� ���� ��� path �˻�
						// path�� ���µ� �湮���� �ִ� ���̸� 
						// �湮�� �ؾ���. (�� ������ �� �� ����)

						// �湮���� ������ ���ٰ� �Ǵ��� �״�� ����
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
				// ���� ���� �ʾҴٸ� �Ѵ´�.
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