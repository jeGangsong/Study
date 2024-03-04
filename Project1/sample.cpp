#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;


struct coord {
    int y, x;
};

int visited[103][103];
int light[103][103];
vector<coord>v[101][101];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int N, M;
int cnt;


void bfs(int y, int x) {
    queue<coord>q;
    q.push({ y,x });
    light[y][x] = 1;
    visited[y][x] = 1;
    for (int j = 0; j < v[y][x].size(); j++) {
        int yy = v[y][x][j].y;
        int xx = v[y][x][j].x;
        light[yy][xx] = 1;
        q.push({ yy,xx });
    }
    while (!q.empty()) {
        coord now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (ny <= 0 || ny > N || nx <= 0 || nx > N)continue;
            if (light[ny][nx] == 0)continue;
            if (visited[ny][nx] == 1)continue;
            q.push({ ny,nx });
            visited[ny][nx] = 1;
            light[ny][nx] = 1;
            for (int j = 0; j < v[ny][nx].size(); j++) {
                int yy = v[ny][nx][j].y;
                int xx = v[ny][nx][j].x;
                light[yy][xx] = 1;
                q.push({ yy,xx });

            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (light[i][j] == 1)cnt++;
        }
    }
    cout << cnt;
}

int main() {

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int y, x, c, d;
        cin >> y >> x >> c >> d;
        v[y][x].push_back({ c,d });
    }

    bfs(1, 1);
}