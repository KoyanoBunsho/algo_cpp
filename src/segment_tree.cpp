#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
template <typename T> struct segtree {
  using F = function<T(T, T)>;
  const F calcfn, updatefn;
  int n;
  T defvalue;
  vector<T> dat;
  segtree(
      int n_ = 0, T defvalue_ = numeric_limits<T>::max(),
      const F calcfn_ = [](T a, T b) { return a < b ? a : b; },
      const F updatefn_ = [](T a, T b) { return b; })
      : defvalue(defvalue_), calcfn(calcfn_), updatefn(updatefn_) {
    n = 1;
    while (n < n_)
      n <<= 1;
    dat.assign(2 * n - 1, defvalue);
  }
  void copy(const vector<T> &v) {
    rep(i, v.size()) dat[i + n - 1] = v[i];
    for (int i = n - 2; i >= 0; i--)
      dat[i] = calcfn(dat[i * 2 + 1], dat[i * 2 + 2]);
  }
  void update(int i, T a) {
    i += n - 1;
    dat[i] = updatefn(dat[i], a);
    while (i > 0) {
      i = (i - 1) / 2;
      dat[i] = calcfn(dat[2 * i + 1], dat[2 * i + 2]);
    }
  }
  T query(int a, int b) {
    int L = (a < 0 ? 0 : a > n ? n : a) + n - 1;
    int R = (b < 0 ? 0 : b > n ? n : b) + n - 1;
    T lret = defvalue, rret = defvalue;
    for (; L < R; L >>= 1, R >>= 1) {
      if (!(L & 1))
        lret = calcfn(lret, dat[L]);
      if (!(R & 1))
        rret = calcfn(dat[--R], rret);
    }
    return calcfn(lret, rret);
  }
};
int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  segtree<int> P(
      N, 0, [](int a, int b) { return a < b ? b : a; },
      [](int a, int b) { return b; });
  P.copy(A);
  rep(i, Q) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t == 1) {
      P.update(l - 1, r);
    } else if (t == 2) {
      cout << P.query(l - 1, r) << endl;
    } else {
      int L = l - 1, R = N + 1;
      while (R - L > 1) {
        int mid = L + R >> 1;
        if (P.query(l - 1, mid) >= r)
          R = mid;
        else
          L = mid;
      }
      cout << R << endl;
    }
  }
  return 0;
}
