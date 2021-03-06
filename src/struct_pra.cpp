#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

struct t {
  int a;
  int b;
};

struct t_func {
  int a;
  int b;
  void f(int v) {
    a = v;
    b = v;
  }
};

struct t_const {
  int a;
  int b;
  t_const(int v) {
    a = v;
    b = 2 * v;
  }
};

struct t_const_init {
  int a;
  int b;
  t_const_init(int v) : a(v), b(2 * v) {}
};

struct t_const_init_vec {
  int a;
  vector<int> b;
  t_const_init_vec(int n) : a(n), b(n, 1) {}
};

struct UnionFind {
  vector<int> par;
  UnionFind(int N) : par(N) { rep(i, N) par[i] = i; }
  int root(int x) {
    if (par[x] == x)
      return x;
    return par[x] = root(par[x]);
  }
  void unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry)
      return;
    par[rx] = ry;
  }
  bool same(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};

int main() {
  t x;
  x.a = 1;
  x.b = 2;
  t_func y;
  y.f(3);
  t_const z(4);
  t_const_init v(4);
  t_const_init_vec w(2);
  cout << x.a << " " << x.b << endl;
  cout << y.a << " " << y.b << endl;
  cout << z.a << " " << z.b << " " << t_const(3).b << endl;
  cout << v.a << " " << v.b << endl;
  cout << w.a << " " << w.b[0] << " " << w.b[1] << endl;
}
