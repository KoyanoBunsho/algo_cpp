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
  lazysegtree(
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
  }
  void copy(const vector<T> &v) {
    rep(i, v.size()) dat[i + n - 1] = v[i];
    for (int i = n - 2; i >= 0; i--)
      dat[i] = calcfn(dat[2 * i + 1], dat[2 * i + 2]);
  }
  void eval(int i, int l, int r) {
    dat[i] = updatefn(dat[i], lazy[i], l, r);
    if (r - l > 1) {
      lazy[2 * i + 1] = lazycalcfn(lazy[2 * i + 1], lazy[i]);
      lazy[2 * i + 2] = lazycalcfn(lazy[2 * i + 2], lazy[i]);
    }
    lazy[i] = lazydefvalue;
  }
  void update(int a, int b, T x, int k = 0, int l = 0, int r = -1) {
    if (r < 0)
      r = n;
    eval(k, l, r);
    if (b <= l || r <= a)
      return;
    else if (a <= l && r <= b) {
      lazy[k] = lazycalcfn(lazy[k], x);
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

int main() {
  int N, Q;
  cin >> N >> Q;
  lazysegtree<pair<long, pair<int, int>>> P(
      N, make_pair(0, make_pair(0, 0)),
      [](pair<long, pair<int, int>> A, pair<long, pair<int, int>> B) {
        return make_pair(A.first + B.first +
                             (long)A.second.second * B.second.first,
                         make_pair(A.second.first + B.second.first,
                                   A.second.second + B.second.second));
      },
      [](pair<long, pair<int, int>> A, pair<long, pair<int, int>> B) {
        A.first ^= B.first;
        return A;
      },
      [](pair<long, pair<int, int>> A, pair<long, pair<int, int>> B, int l,
         int r) {
        if (B.first == 0)
          return A;
        else {
          return make_pair((long)(r - l) * (r - l - 1) / 2 - A.first -
                               (long)A.second.first * (A.second.first - 1) / 2 -
                               (long)A.second.second * (A.second.second - 1) /
                                   2,
                           make_pair(A.second.second, A.second.first));
        }
      },
      make_pair(0, make_pair(0, 0)));
  vector<pair<long, pair<int, int>>> init(N);
  rep(i, N) {
    int t;
    cin >> t;
    if (t == 0)
      init[i].second.first++;
    else
      init[i].second.second++;
  }
  P.copy(init);
  rep(i, Q) {
    int t, l, r;
    cin >> t >> l >> r;
    l--;
    if (t == 1)
      P.update(l, r, make_pair(1, make_pair(0, 0)));
    else
      cout << P.query(l, r).first << endl;
  }
  return 0;
}
