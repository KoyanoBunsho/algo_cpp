#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

struct bimatch {
  int n;
  vector<vector<int>> G;
  vector<int> match;
  vector<bool> used;
  bimatch(int _n = 0) : n(_n), G(n), match(n), used(n) {}
  void add_edge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
  }
  bool dfs(int v) {
    used[v] = true;
    for (int u : G[v]) {
      int w = match[u];
      if (w < 0 || !used[w] && dfs(w)) {
        match[v] = u;
        match[u] = v;
        return true;
      }
    }
    return false;
  }
  int count() {
    int ans = 0;
    bool flag = true;
    fill(match.begin(), match.end(), -1);
    while (flag) {
      flag = false;
      fill(used.begin(), used.end(), false);
      rep(v, n) if (match[v] < 0 && dfs(v)) ans++, flag = true;
    }
    return ans;
  }
};

int N, M;
string S[100];
int main() {
  cin >> N >> M;
  rep(i, N) cin >> S[i];
  bimatch P(N * M);
  rep(i, N) {
    rep(j, M) {
      if (S[i][j] == '.') {
        rep(r, 2) {
          int x = i + (r == 0), y = j + (r == 1);
          if (x < N && y < M && S[x][y] == '.') {
            P.add_edge(i * M + j, x * M + y);
          }
        }
      }
    }
  }
  cout << P.count() << endl;
  rep(i, N) {
    rep(j, M) {
      if (S[i][j] == '.' && P.match[i * M + j] >= 0) {
        int x = P.match[i * M + j] / M, y = P.match[i * M + j] % M;
        S[i][j] = x < i ? '^' : x > i ? 'v' : y < j ? '<' : '>';
      }
    }
  }
  rep(i, N) cout << S[i] << endl;
  return 0;
}
