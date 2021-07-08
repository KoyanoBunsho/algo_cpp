#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long

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

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  vector<int> idx(n);
  rep(i, n) {
    cin >> p[i];
    p[i]--;
  }
  UnionFind uf(n);
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    uf.unite(x, y);
  }
  int ans = 0;
  map<int, set<int>> perm, index;
  rep(i, n) {
    int r = uf.find(i);
    perm[r].insert(p[i]);
    index[r].insert(i);
  }
  for (map<int, set<int>>::iterator it = perm.begin(); it != perm.end(); ++it) {
    ll tmp = 0;
    int r = it->first;
    set<int> se = it->second;
    for (set<int>::iterator it2 = se.begin(); it2 != se.end(); ++it2) {
      if (index[r].count(*it2))
        ++tmp;
    }
    ans += tmp;
  }
  cout << ans << endl;
  return 0;
}
