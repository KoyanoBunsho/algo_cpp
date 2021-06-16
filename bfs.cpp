#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define P pair<int, int>

int R, C, sx, sy, gx, gy;
const int MAX_R = 55;
const int MAX_C = 55;
int dist[MAX_R][MAX_C];
bool visited[MAX_R][MAX_C];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
string maze[MAX_R];

int bfs(int sx, int sy, int gx, int gy) {
  queue<P> que;
  dist[sx][sy] = 0;
  que.push(make_pair(sx, sy));
  while (!que.empty()) {
    int x = que.front().first;
    int y = que.front().second;
    que.pop();
    visited[x][y] = true;
    rep(i, 4) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (!visited[nx][ny] && nx >= 0 && nx < R && ny >= 0 && ny < C &&
          maze[nx][ny] != '#') {
        dist[nx][ny] = dist[x][y] + 1;
        visited[nx][ny] = true;
        que.push(make_pair(nx, ny));
      }
    }
  }
  return dist[gx][gy];
}

int main() {
  cin >> R >> C >> sy >> sx >> gy >> gx;
  sx--;
  sy--;
  gx--;
  gy--;
  rep(i, R) { cin >> maze[i]; }
  int ans = bfs(sy, sx, gy, gx);
  cout << ans << endl;
  return 0;
}
