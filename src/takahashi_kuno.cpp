#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define P pair<int, int>

int dp[55][11111];
int main() {
  int W;
  cin >> W;
  int N, K;
  cin >> N >> K;
  vector<int> a(N), b(N);
  rep(i, N) { cin >> a[i] >> b[i]; }
  rep(i, N) {
    for (int j = K; j--;) {
      rep(l, W - a[i] + 1) {
        dp[j + 1][l + a[i]] = std::max(dp[j + 1][l + a[i]], dp[j][l] + b[i]);
      }
    }
  }
  cout << dp[K][W] << endl;
  return 0;
}
