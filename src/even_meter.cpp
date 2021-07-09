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
  int n, q;
  cin >> n >> q;
  UnionFind uf(2 * n);
  rep(i, q) {
    int w, x, y, z;
    cin >> w >> x >> y >> z;
    --x;
    --y;
    if (w == 1) {
      if (z % 2 == 0) {
        uf.unite(x, y);
        uf.unite(x + n, y + n);
      } else {
        uf.unite(x, y + n);
        uf.unite(x + n, y);
      }
    } else {
      if (uf.same(x, y))
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}
