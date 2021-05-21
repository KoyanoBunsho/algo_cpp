#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
const int MAX_K = 100005;
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

int N, K;
int T[MAX_K], X[MAX_K], Y[MAX_K];
int main() {
  cin >> N >> K;
  rep(i, K) { cin >> T[i] >> X[i] >> Y[i]; }
  int ans = 0;
  UnionFind uf(N * 3);
  rep(i, K) {
    int t = T[i];
    int x = X[i] - 1, y = Y[i] - 1;
    if (x < 0 || N <= x || y < 0 || N <= y) {
      ans++;
      continue;
    }
    if (t == 1) {
      if (uf.same(x, y + N) || uf.same(x, y + 2 * N)) {
        ans++;
      } else {
        uf.unite(x, y);
        uf.unite(x + N, y + N);
        uf.unite(x + N * 2, y + N * 2);
      }
    } else {
      if (uf.same(x, y) || uf.same(x, y + 2 * N)) {
        ans++;
      } else {
        uf.unite(x, y + N);
        uf.unite(x + N, y + 2 * N);
        uf.unite(x + 2 * N, y);
      }
    }
  }
  cout << ans << endl;
}
