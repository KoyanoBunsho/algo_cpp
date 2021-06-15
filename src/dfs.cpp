#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
const int MAX_H = 505;
const int MAX_W = 505;
char c[MAX_H][MAX_W];
bool visited[MAX_H][MAX_W];
int H, W;

bool dfs(int sx, int sy) {
  visited[sx][sy] = true;
  if (c[sx][sy] == 'g')
    return false;
  bool flg = 1;
  rep(i, 4) {
    int nx = dx[i] + sx;
    int ny = dy[i] + sy;
    if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] &&
        c[nx][ny] != '#') {
      flg &= dfs(nx, ny);
    }
  }
  return flg;
}

int main() {
  cin >> H >> W;
  int sx, sy, gx, gy;
  rep(i, H) {
    rep(j, W) {
      char val;
      cin >> val;
      c[i][j] = val;
      if (val == 's') {
        sx = i;
        sy = j;
      }
    }
  }
  bool ans = dfs(sx, sy);
  if (!ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
