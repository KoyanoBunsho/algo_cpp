#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long

using Edge = pair<int, ll>;
using Graph = vector<vector<Edge>>;

Graph G;
vector<int> dir;
int n;
void dfs(int v, int p, int c) {
  dir[v] = c;
  for (auto e : G[v]) {
    if (e.first == p)
      continue;
    if (e.second & 1)
      dfs(e.first, v, 1 - c);
    else
      dfs(e.first, v, c);
  }
}

int main() {
  cin >> n;
  G.assign(n, vector<Edge>());
  rep(i, n - 1) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    --u;
    --v;
    G[u].push_back(Edge(v, w));
    G[v].push_back(Edge(u, w));
  }
  dir.assign(n, 0);
  dfs(0, -1, 1);
  for (auto v : dir)
    cout << v << endl;
  return 0;
}
