#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

long dp[2001];
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> a(N), s(N);
  rep(i, N) {
    cin >> a[i];
    s[i] = a[i];
    if (i > 0)
      s[i] += s[i - 1];
  }
  if (s[N - 1] == K)
    cout << 1 << endl;
  else {
    rep(i, N + 1) dp[i] = 1LL << 60;
    dp[0] = 0;
    rep(i, N) {
      for (int j = i; j >= 0; j--) {
        long b = i == 0 ? 1 : dp[j] * a[i] / s[i - 1] + 1;
        dp[j + 1] = min(dp[j + 1], dp[j] + b);
      }
    }
    for (int i = N; i >= 0; i--) {
      if (dp[i] <= K) {
        cout << i << endl;
        break;
      }
    }
  }
  return 0;
}
