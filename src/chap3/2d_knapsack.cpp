#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int dp[100010][100010];
int main() {
  int n, W;
  cin >> n >> W;
  vector<int> w(n), v(n);
  rep(i, n) cin >> v[i] >> w[i];
  rep(i, W + 1) dp[0][i] = 0;
  rep(i, n) {
    rep(j, W + 1) {
      if (j >= w[i]) {
        dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
      } else {
        dp[i + 1][j] = dp[i][j];
      }
    }
  }
  cout << dp[n][W] << endl;
  return 0;
}
