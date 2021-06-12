#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

const int MAX_H = 1005;
const int MAX_W = 1005;
char maze[MAX_H][MAX_W];
int dist[MAX_H][MAX_W];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool visited[MAX_H][MAX_W];

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  queue<pair<int, int>> que;
  rep(i, h) {
    rep(j, w) {
      char dot;
      cin >> dot;
      maze[i][j] = dot;
      if (dot == 'S')
        que.push(make_pair(i, j));
    }
  }
  while (!que.empty()) {
    int x = que.front().first;
    int y = que.front().second;
    que.pop();
    visited[x][y] = true;
    int phys = 1;
    rep(i, 4) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (0 <= nx && nx < h && 0 <= ny && ny < w && dist[nx][ny] <= 0 &&
          !visited[nx][ny] && maze[nx][ny] != 'X') {
        if (maze[nx][ny] != '.' || maze[nx][ny] <= phys) {
          phys += 1;
          dist[nx][ny] = dist[x][y] + 1;
        } else {
          dist[nx][ny] = dist[x][y] + 1;
        }
        que.push(make_pair(nx, ny));
      }
    }
  }
  int ans = 0;
  rep(i, h) {
    rep(j, w) { ans = max(ans, dist[i][j]); }
  }
  cout << ans << endl;
  return 0;
}
