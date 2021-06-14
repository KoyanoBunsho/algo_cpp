#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
string A[10];

void dfs(int sx, int sy, bool visited[][10]) {
  visited[sx][sy] = true;
  rep(i, 4) {
    int nx = dx[i] + sx;
    int ny = dy[i] + sy;
    if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10 && A[nx][nx] != 'x' &&
        !visited[nx][ny]) {
      dfs(nx, ny, visited);
    }
  }
}

int main() {
  bool f = true;
  rep(i, 10) cin >> A[i];
  rep(i, 10) {
    rep(j, 10) {
      if (A[i][j] == 'o')
        continue;
      bool ff = true;
      bool visited[10][10] = {};
      dfs(i, j, visited);
      rep(k, 10) {
        rep(l, 10) { ff &= A[k][l] == 'x' || visited[k][l]; }
      }
      if (ff) {
        cout << "YES" << endl;
        return 0;]
      }
    }
    cout << "NO" << endl;
    return 0;
  }
