#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define P pair<int, int>

int main() {
  int N;
  cin >> N;
  vector<P> xl(N);
  rep(i, N) { cin >> xl[i].second >> xl[i].first; }
  sort(xl.begin(), xl.end());
  int ans = 0, t = 0;
  rep(i, N) {
    if (t <= xl[i].second) {
      ans++;
      t = xl[i].first;
    }
  }
  cout << ans << endl;
  return 0;
}
