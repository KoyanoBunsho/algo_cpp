#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

template <typename T> struct lazysegtree {
  using F = function<T(T, T)>;
  using G = function<T(T, T, int, int)>;
  const F calcfn, lazycalcfn;
  const G updatefn;
  int n;
  T defvalue, lazydefvalue;
  vector<T> dat, lazy;
  vector<bool> lazyflag;
  lasysegtree(
      int n_ = 0, T defvalue_ = 0,
      const F calcfn_ = [](T a, T b) { return a + b; },
      const F lazycalcfn_ = [](T a, T b) { return a + b; },
      const G updatefn_ = [](T a, T b, int l,
                             int r) { return a + b * (r - l); },
      T lazydefvalue_ = 0)
      : defvalue(defvalue_), lazydefvalue(lazydefvalue_), calcfn(calcfn_),
        lazycalcfn(lazycalcfn_), updatefn(updatefn_) {
    n = 1;
    while (n < n_)
      n <<= 1;
    dat.assign(2 * n - 1, defvalue);
    lazy.assign(2 * n - 1, lazydefvalue);
    lazyflag.assign(2 * n - 1, false);
  }
  void copy(const vector<T> &v) {
    rep(i, v.size()) dat[i + n - 1] = v[i];
    for (int i = n - 2; i >= 0; i--)
      dat[i] = calcfn(dat[2 * i + 1], dat[2 * i + 2]);
  }
  void eval(int i, int l, int r) {
    if (lazyflag[i]) {
      dat[i] = updatefn(dat[i], lazy[i], l, r);
      if (r - l > 1) {
        lazy[2 * i + 1] = lazycalcfn(lazy[2 * i + 1], lazy[i]);
        lazy[2 * i + 2] = lazycalcfn(lazy[2 * i + 2], lazy[i]);
        lazyflag[2 * i + 1] = lazyflag[2 * i + 2] = true;
      }
      lazy[i] = lazydefvalue;
      lazyflag[i] = false;
    }
  }
  void update(int a, int b, T x, int k = 0, int l = 0, int r = -1) {
    if (r < 0)
      r = n;
    eval(k, l, r);
    if (b <= l || r <= a)
      return;
    else if (a <= l && r <= b) {
      lazy[k] = lazycalcfn(lazy[k], x);
      lazyflag[k] = true;
      eval(k, l, r);
    } else {
      update(a, b, x, 2 * k + 1, l, (l + r) / 2);
      update(a, b, x, 2 * k + 2, (l + r) / 2, r);
      dat[k] = calcfn(dat[2 * k + 1], dat[2 * k + 2]);
    }
  }
  T query(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r < 0)
      r = n;
    eval(k, l, r);
    if (b <= l || r <= a)
      return defvalue;
    else if (a <= l && r <= b)
      return dat[k];
    else
      return calcfn(query(a, b, 2 * k + 1, l, (l + r) / 2),
                    query(a, b, 2 * k + 2, (l + r) / 2, r));
  }
};

const long mod = 998244353;

int main() {
  int N, Q;
  cin >> N >> Q;
  lazysegtree<pair<long, long>> P(
      N, make_pair(0, 0),
      [](pair<long, long> a, pair<long, long> b) {
        return make_pair((a.first + b.first) % mod, 0);
      },
      [](pair<long, long> a, pair<long, long> b) {
        return make_pair(a.first * b.first % mod,
                         (a.second * b.first + b.second) % mod);
      },
      [](pair<long, long> a, pair<long, long> b, int l, int r) {
        return make_pair(
            (a.first * b.first % mod + b.second * (r - l) % mod) % mod, 0);
      },
      make_pair(1, 0));
  vector<pair<long, long>> A(N);
  rep(i, N) cin >> A[i].first;
  P.copy(A);
  rep(i, Q) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t == 0) {
      pair<long, long> q;
      cin >> q.first >> q.second;
      P.update(l, r, q);
    } else {
      cout << P.query(l, r).first << endl;
    }
  }
  return 0;
}
