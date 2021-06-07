#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define P pair<int, int>

const int MAX_H = 55;
const int MAX_W = 55;
const int INF = 100000000;
char maze[MAX_W][MAX_H];
int dist[MAX_W][MAX_H];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int H, W;

int bfs() {
  queue<P> que;
  rep(i, W) {
    rep(j, H) { dist[i][j] = INF; }
  }
  que.push(P(0, 0));
  dist[0][0] = 0;
  while (!que.empty()) {
    P p = que.front();
    que.pop();
    if (p.first - 1 == W && p.second == H - 1)
      break;
    rep(i, 4) {
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];
      if (0 <= nx && nx < W && 0 <= ny && ny < H && maze[nx][ny] != '#' &&
          dist[nx][ny] == INF) {
        que.push(P(nx, ny));
        dist[nx][ny] = dist[p.first][p.second] + 1;
      }
    }
  }
  return dist[W - 1][H - 1];
}

int main() {
  cin >> H >> W;
  int black = 0;
  rep(i, H) {
    rep(j, W) {
      char s;
      cin >> s;
      if (s == '#')
        black++;
      maze[i][j] = s;
    }
  }
  int res = bfs();
  cout << H * W - res - black - 1 << endl;
  return 0;
}
