#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long

ll x[21];

ll floor_sum(ll N, ll M, ll A, ll B) {
  ll ans = 0;
  if (B >= M) {
    ll B_div_M = B / M;
    ll B_mod_M = B % M;
    ans += N * B_div_M;
    B = B_mod_M;
  }
  if (A >= M) {
    ll A_div_M = A / M;
    ll A_mod_M = A % M;
    ans += (N * (N - 1) >> 1) * A_div_M;
    A = A_mod_M;
  }
  if (A == 0)
    return ans;
  if (B >= A) {
    ll B_div_A = B / A;
    ll B_mod_A = B % A;
    N += B_div_A;
    B = B_mod_A;
  }
  ll M_div_A = M / A;
  ll M_mod_A = M % A;
  ll lastTerm = B + A * (N - 1);
  ll maxNum = lastTerm / M;
  ll temp = (lastTerm % M) / A;
  ll cntMax = min(1 + temp, M_div_A);
  ans += cntMax * ((maxNum * (maxNum + 1)) >> 1);
  ans += (M_div_A - cntMax) * ((maxNum * (maxNum - 1)) >> 1);
  if (M_mod_A) {
    ll new_maxNum = maxNum + (temp == M_div_A);
    ll new_N = (new_maxNum * M_mod_A + A - B - 1) / A;
    ans += floor_sum(new_N, M_mod_A, A, B);
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  rep(i, T) {
    ll N, M, A, B;
    cin >> N >> M >> A >> B;
    ll ans;
    ans = floor_sum(N, M, A, B);
    cout << ans << endl;
  }
  return 0;
}
