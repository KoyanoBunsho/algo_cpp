#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long

int main() {
  int N;
  cin >> N;
  vector<ll> a(N * 3);
  rep(i, 3 * N) cin >> a[i];
  vector<ll> s(N * 2 + 1, 0);
  priority_queue<ll, vector<ll>, greater<ll>> que;
  rep(i, N) {
    s[i + 1] = s[i] + a[i];
    que.push(a[i]);
  }
  for (int i = N; i < N * 2; ++i) {
    ll mi = que.top();
    if (a[i] > mi) {
      s[i + 1] = s[i] - mi + a[i];
      que.pop();
      que.push(a[i]);
    } else {
      s[i + 1] = s[i];
    }
  }
  vector<ll> t(N * 2 + 1, 0);
  priority_queue<ll> que2;
  rep(i, N) {
    t[i + 1] = t[i] + a[N * 3 - 1 - i];
    que2.push(a[N * 3 - 1 - i]);
  }
  for (int i = N; i < N * 2; i++) {
    ll ma = que2.top();
    if (a[N * 3 - 1 - i] < ma) {
      t[i + 1] = t[i] - ma + a[N * 3 - 1 - i];
      que2.pop();
      que2.push(a[N * 3 - 1 - i]);
    } else {
      t[i + 1] = t[i];
    }
  }
  ll res = -(1LL << 60);
  for (int i = N; i <= N * 2; i++) {
    res = max(res, s[i] - t[N * 3 - i]);
  }
  cout << res << endl;
  return 0;
}
