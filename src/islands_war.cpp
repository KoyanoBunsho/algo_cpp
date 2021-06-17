#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define P pair<int, int>

int main() {
  int N, M;
  cin >> N >> M;
  vector<P> a(M);
  rep(i, M) { cin >> a[i].second >> a[i].first; }
  sort(a.begin(), a.end());
  int ans = 0;
  int t = 0;
  rep(i, M) {
    if (t < a[i].second) {
      ans++;
      t = a[i].first - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
