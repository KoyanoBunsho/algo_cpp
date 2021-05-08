#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long
template <int mod, int proot> struct NTT {
  vector<ll> pp, invpp;
  ll power(ll a, int b) {
    ll ret = 1;
    while (b) {
      if (b & 1) {
        ret = ret * a % mod;
      }
      a = a * a % mod;
      b >>= 1;
    }
    return ret;
  }
  void dft(vector<int> &A, bool sign, int id) {
    if (id == 0)
      return;
    int N = 1 << id - 1;
    vector<int> F(N), G(N);
    rep(i, N) {
      F[i] = A[i << 1];
      G[i] = A[i << 1 | 1];
    }
    dft(F, sign, id - 1);
    dft(G, sign, id - 1);
    ll z = (sign ? invpp : pp)[id], p = 1;
    rep(i, N) {
      A[i] = (F[i] + p * G[i]) % mod;
      A[i + N] = (F[i] - p * G[i]) % mod;
      if (A[i + N] < 0)
        A[i + N] += mod;
      (p *= z) %= mod;
    }
  }
  vector<int> multiply(vector<int> A, vector<int> B) {
    if (A.empty() || B.empty()) {
      return (vector<int>){};
    }
    int N = 1, sz = 0;
    vector<int> ret(A.size() + B.size() - 1);
    while (N < ret.size())
      N <<= 1, sz += 1;
    pp.resize(sz + 1);
    invpp.resize(sz + 1);
    pp[sz] = power(proot, mod - 1 >> sz);
    invpp[sz] = power(pp[sz], mod - 2);
    for (int i = sz - 1; i > 0; i -= 1) {
      pp[i] = pp[i + 1] * pp[i + 1] % mod;
      invpp[i] = invpp[i + 1] * invpp[i + 1] % mod;
    }
    A.resize(N);
    B.resize(N);
    dft(A, false, sz);
    dft(B, false, sz);
    rep(i, N) A[i] = (ll)A[i] * B[i] % mod;
    dft(A, true, sz);
    ll invN = power(N, mod - 2);
    rep(i, ret.size()) ret[i] = invN * A[i] % mod;
    return ret;
  }
};

int main() {
  int N, M;
  cin >> N >> M;
  NTT<998244353, 3> P;
  vector<int> A(N), B(M);
  rep(i, N) cin >> A[i];
  rep(i, M) cin >> B[i];
  A = P.multiply(A, B);
  rep(i, N + M - 1) cout << A[i] << (i == N + M - 2 ? "\n" : " ");
  return 0;
}
