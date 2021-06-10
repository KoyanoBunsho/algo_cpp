#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
int main() {
  int H, W;
  cin >> H >> W;
  string C[500];
  rep(i, H) { cin >> C[i]; }
  int si, sj, gi, gj;
  rep(i, H) {
    int j = C[i].find('s');
    if (j >= 0) {
      si = i;
      sj = j;
    }
    j = C[i].find('g');
    if (j >= 0) {
      gi = i;
      gj = j;
    }
  }
  int dist[500][500];
  rep(i, H) {
    rep(j, W) { dist[i][j] = 1e9; }
  }
  dist[si][sj] = 0;
  const int di[4] = {0, 0, 1, -1};
  const int dj[4] = {1, -1, 0, 0};
  deque<pair<int, int>> que;
  que.push_back({si, sj});
  while (!que.empty()) {
    auto p = que.front();
    que.pop_front();
    int i = p.first;
    int j = p.second;
    rep(k, 4) {
      int i2 = i + di[k];
      int j2 = j + dj[k];
      if (0 <= i2 && i2 < H && 0 <= j2 && j2 < W) {
        bool wall = (C[i][j] == '#');
        int d2 = dist[i][j] + wall;
        if (dist[i2][j2] > d2) {
          dist[i2][j2] = d2;
          if (wall) {
            que.push_back({i2, j2});
          } else {
            que.push_front({i2, j2});
          }
        }
      }
    }
  }
  cout << (dist[gi][gj] <= 2 ? "YES" : "NO") << endl;
  return 0;
}
