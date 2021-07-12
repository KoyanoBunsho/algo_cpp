#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define P pair<ll, ll>
const int MAX_N = 100005;
vector<ll> x(MAX_N), y(MAX_N);
vector<ll> min_cost_vec(MAX_N);
using Edge = pair<ll, P>;
vector<Edge> edges;

struct UnionFind {
  vector<int> par;
  vector<int> sizes;
  UnionFind(int n) : par(n), sizes(n, 1) { rep(i, n) par[i] = i; }
  int find(int x) {
    if (x == par[x])
      return x;
    return par[x] = find(par[x]);
  }
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
      return;
    if (sizes[x] < sizes[y])
      swap(x, y);
    par[y] = x;
    sizes[x] += sizes[y];
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return sizes[find(x)]; }
};
int n;
int kruskal() {
  sort(edges.begin(), edges.end());
  UnionFind uf(n);
  ll res = 0;
  for (auto e : edges) {
    int u = e.second.first, v = e.second.second;
    ll cost = e.first;
    if (uf.same(u, v))
      continue;
    uf.unite(u, v);
    res += cost;
  }
  return res;
}

int main() {
  cin >> n;
  UnionFind uf(n);
  rep(i, n) { cin >> x[i] >> y[i]; }
  vector<int> ids(n);
  iota(ids.begin(), ids.end(), 0);
  sort(ids.begin(), ids.end(), [&](int i, int j) { return x[i] < x[j]; });
  rep(i, ids.size() - 1) {
    int u = ids[i];
    int v = ids[i + 1];
    edges.push_back(Edge(x[v] - x[u], P(u, v)));
  }
  sort(ids.begin(), ids.end(), [&](int i, int j) { return y[i] < y[j]; });
  rep(i, ids.size() - 1) {
    int u = ids[i], v = ids[i + 1];
    edges.push_back(Edge(y[v] - y[u], P(u, v)));
  }
  int res = kruskal();
  cout << res << endl;
  return 0;
}
