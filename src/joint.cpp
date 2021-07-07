#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

struct UnionFind {
  vector<int> par;
  vector<int> sizes;
  UnionFind(int n) : par(n), sizes(n, 1) { rep(i, n) par[i] = i; }
  int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
  }
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (sizes[x] < sizes[y]) swap(x, y);
    par[y] = x;
    sizes[x] += sizes[y];
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return sizes[find(x)]; }
};

int main(){
  int N, K, L;
  cin >> N >> K >> L;
  UnionFind uf_road(N);
  UnionFind uf_rail(N);
  vector<int>p(K), q(K);
  rep(i, K){
    int a, b;
    cin >> a >> b;
    a--; b--;
    uf_road.unite(a, b);
  };
  vector<int> r(L), s(L);
  rep(i, L) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    uf_rail.unite(a, b);
  };
  map<pair<int, int>, int> ma;
  rep(i, N){
    ma[make_pair(uf_road.find(i), uf_rail.find(i))]++;
  }
  rep(i, N){
    cout << ma[make_pair(uf_road.find(i), uf_rail.find(i))] << endl;
  }
  return 0;
}
