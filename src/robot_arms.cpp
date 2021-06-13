#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define P pair<int, int>

int main() {
  int N;
  cin >> N;
  vector<P> xl(N);
  rep(i, N) {
    int x, l;
    cin >> x >> l;
    xl[i] = make_pair(x + l, x - l);
  }
  sort(xl.begin(), xl.end());
  int ans = 0, t = -1e9;
  rep(i, N) {
    if (t <= xl[i].second) {
      ans++;
      t = xl[i].first;
    }
  }
  cout << ans << endl;
  return 0;
}
