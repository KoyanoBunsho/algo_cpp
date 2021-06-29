#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

template <class T> int LIS(vector<T> a, bool is_strong = true) {
  const T INF = 1 << 30;
  int n = (int)a.size();
  vector<T> dp(n, INF);
  rep(i, n) {
    if (is_strong)
      *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
    else
      *upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
  }
  return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

int main() {
  int N;
  cin >> N;
  vector<int> c(N);
  rep(i, N) cin >> c[i];
  cout << N - LIS(c) << endl;
  return 0;
}
