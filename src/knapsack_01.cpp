#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int dp[205][200005];
const int INF = 1e9;
const int MAX_V = 205;

int main() {
  int N, W;
  cin >> N >> W;
  vector<int> v(N), w(N);
  rep(i, N) { cin >> v[i] >> w[i]; }
  fill(dp[0], dp[0] + N * MAX_V + 1, INF);
  dp[0][0] = 0;
  rep(i, N) {
    rep(j, N * MAX_V + 1) {
      if (j < v[i]) {
        dp[i + 1][j] = dp[i][j];
      } else {
        dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i] + w[i]]);
      }
    }
  }
  int res = 0;
  rep(i, N * W + 1) {
    if (dp[N][i] <= W)
      res = i;
  }
  cout << res << endl;
  return 0;
}
