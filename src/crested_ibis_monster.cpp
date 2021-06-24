#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long

int H, N;
const int INF = 1e9;

int main() {
  cin >> H >> N;
  vector<int> A(N), B(N);
  rep(i, N) { cin >> A[i] >> B[i]; }
  vector<vector<ll>> dp(N + 1, vector<ll>(H + 1, INF));
  dp[0][0] = 0;
  rep(i, N) {
    rep(j, H + 1) {
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      dp[i + 1][j] = min(dp[i + 1][j], dp[i + 1][max(j - A[i], 0)] + B[i]);
    }
  }
  cout << dp[N][H] << endl;
  return 0;
}
