#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  rep(i, n) { cin >> v[i]; }
  set<int> ans;
  do {
    string res = "";
    rep(i, k) { res += to_string(v[i]); };
    ans.insert(stoi(res));
  } while (next_permutation(v.begin(), v.end()));
  cout << ans.size() << endl;
  return 0;
}
