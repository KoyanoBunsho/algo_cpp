#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long

struct SCC {
  int n;
  vector<int> comp, order;
  vector<bool> used;
  vector<vector<int>> G, RG;
  SCC(int _n = 0) : n(_n), comp(_n, -1), used(_n, false), G(_n), RG(_n) {}
  void add_edge(int from, int to) {
    G[from].push_back(to);
    RG[to].push_back(from);
  }
  void copy(const vector<vector<int>> &H) {
    rep(i, H.size()) {
      rep(j, H.size()) {
        G[i].push_back(H[i][j]);
        RG[H[i][j]].push_back(i);
      }
    }
  }
  int operator[](int u) const { return comp[u]; }
  void dfs(int u) {
    used[u] = true;
    rep(i, G[u].size()) {
      if (!used[G[u][i]])
        dfs(G[u][i]);
    }
    order.push_back(u);
  }
  void rdfs(int u, int cnt) {
    comp[u] = cnt;
    rep(i, RG[u].size()) {
      if (comp[RG[u][i]] == -1)
        rdfs(RG[u][i], cnt);
    }
  }
  int build() {
    rep(i, n) if (!used[i]) dfs(i);
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--)
      if (comp[order[i]] == -1)
        rdfs(order[i], cnt++);
    return cnt;
  }
  int build(vector<vector<int>> &H) {
    int ret = build();
    H.assign(ret, vector<int>());
    rep(i, n) {
      rep(j, G[i].size()) {
        if (comp[i] != comp[G[i][j]])
          H[comp[i]].push_back(comp[G[i][j]]);
      }
    }
    return ret;
  }
};

int N, M;

int main() {
  cin >> N >> M;
  SCC P(N);
  rep(i, M) {
    int u, v;
    cin >> u >> v;
    P.add_edge(u, v);
  }
  int K = P.build();
  cout << K << endl;
  vector<vector<int>> ans(K);
  rep(i, N) ans[P[i]].push_back(i);
  rep(i, K) {
    cout << ans[i].size();
    for (int v : ans[i])
      cout << " " << v;
    cout << endl;
  }
  return 0;
}
