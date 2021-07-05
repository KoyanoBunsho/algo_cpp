#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
  int n, m;
  cin >> n;
  map<string, int> n_map;
  rep(i, n) {
    string s;
    cin >> s;
    n_map[s]++;
  };
  cin >> m;
  rep(i, m) {
    string t;
    cin >> t;
    n_map[t]--;
  };
  int ans = 0;
  for (auto it : n_map) {
    ans = max(ans, it.second);
  }
  cout << ans << endl;
  return 0;
}
