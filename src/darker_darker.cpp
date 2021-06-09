#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define P pair<int, int>

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int H, W;
const int INF = 1e9;
const int MAX_H = 1005;
const int MAX_W = 1005;
char maze[MAX_H][MAX_W];
int dist[MAX_H][MAX_W];

int main() {
  cin >> H >> W;
  rep(i, H) {
    rep(j, W) { cin >> maze[i][j]; }
  }
  queue<P> p;
  rep(i, H) {
    rep(j, W) {
      if (maze[i][j] == '#') {
        dist[i][j] = 1;
        p.push(make_pair(i, j));
      }
    }
  }
  while (!p.empty()) {
    int x = p.front().first;
    int y = p.front().second;
    p.pop();
    rep(i, 4) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (0 <= nx && nx < H && 0 <= ny && ny < W && dist[nx][ny] <= 0) {
        dist[nx][ny] = dist[x][y] + 1;
        p.push(make_pair(nx, ny));
      }
    }
  }
  int ans = 0;
  rep(i, H) {
    rep(j, W) { ans = max(dist[i][j], ans); }
  }
  cout << ans - 1 << endl;
  return 0;
}
