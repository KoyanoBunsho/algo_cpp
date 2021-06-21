#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define P pair<int, int>
const int INF = 1e9;
int main() {
  int N;
  cin >> N;
  vector<P> ab(N);
  vector<P> cd(N);
  rep(i, N) {
    int a, b;
    cin >> a >> b;
    ab[i] = make_pair(a, b);
  }
  rep(i, N) {
    int c, d;
    cin >> c >> d;
    cd[i] = make_pair(c, d);
  }
  sort(ab.rbegin(), ab.rend());
  int ans = 0;
  rep(i, N) {
    int min_d = INF, min_j;
    rep(j, N) {
      if (cd[j].first > ab[i].first && cd[j].second > ab[i].second &&
          min_d > cd[j].second) {
        min_d = cd[j].second;
        min_j = j;
      }
    }
    if (min_d != INF) {
      ans++;
      cd[min_j].first = -1;
    }
  }
  cout << ans << endl;
  return 0;
}
