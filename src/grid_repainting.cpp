#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define P pair<int, int>

const int MAX_H = 55;
const int MAX_W = 55;
const int INF = 1e9;
char maze[MAX_H][MAX_W];
int dist[MAX_H][MAX_W];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int H, W;

int bfs() {
  queue<P> que;
  rep(i, H) {
    rep(j, W) { dist[i][j] = INF; }
  }
  que.push(make_pair(0, 0));
  dist[0][0] = 1;
  while (!que.empty()) {
    P p = que.front();
    que.pop();
    rep(i, 4) {
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];
      if (0 <= nx && nx < H && 0 <= ny && ny < W && maze[nx][ny] != '#' &&
          dist[nx][ny] == INF) {
        que.push(make_pair(nx, ny));
        dist[nx][ny] = dist[p.first][p.second] + 1;
      }
    }
  }
  return dist[H - 1][W - 1];
}

int main() {
  cin >> H >> W;
  int white = 0;
  rep(i, H) {
    rep(j, W) {
      char s;
      cin >> s;
      if (s == '.')
        white++;
      maze[i][j] = s;
    }
  }
  int res = bfs();
  if (res < 1e9) {
    cout << white - res << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
