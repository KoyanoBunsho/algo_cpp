#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long

const int MAX = 210000;
const int MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

vector<pair<ll, ll>> prime_factorize(ll n) {
  vector<pair<ll, ll>> res;
  for (ll p = 2; p * p <= n; p++) {
    if (n % p != 0)
      continue;
    int num = 0;
    while (n % p == 0) {
      ++num;
      n /= p;
    }
    res.push_back(make_pair(p, num));
  }
  if (n != 1)
    res.push_back(make_pair(n, 1));
  return res;
}

void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

ll COM(int n, int k) {
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
  ll n, m;
  COMinit();
  cin >> n >> m;
  auto vec = prime_factorize(m);
  ll res = 1;
  for (auto pa : vec) {
    int k = pa.second;
    ll tmp = COM(n + k - 1, k);
    res = (res * tmp) % MOD;
  }
  cout << res << endl;
  return 0;
}
