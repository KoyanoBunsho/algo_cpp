#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (int i = 0; i < N; i++)

bool chmin(long long &a, long long b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

const long long INF = 1LL << 50;
int main() {
  int N, M;
  long long X;
  cin >> N >> M >> X;
  vector<long long> H(N);
  rep(i, N) cin >> H[i];
  using Edge = pair<int, long long>;
  using Graph = vector<vector<Edge>>;
  Graph G(N);
  rep(i, M) {
    int a, b;
    long long w;
    cin >> a >> b >> w;
    --a;
    --b;
    G[a].emplace_back(b, w);
    G[b].emplace_back(a, w);
  }
  auto calc_height = [&](int v, long long dis) -> long long {
    long long res = max(0LL, X - dis);
    chmin(res, H[v]);
    return res;
  };
  auto calc_dist = [&](int from, int to, long long height,
                       long long w) -> long long {
    if (height - w >= H[to])
      return height - H[to];
    else if (height - w >= 0)
      return w;
    else if (H[from] - w >= 0)
      return w * 2 - height;
    else
      return INF;
  };
  vector<long long> dp(N, INF);
  dp[0] = 0;
  priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                 greater<pair<long long, int>>>
      que;
  que.push({0, 0});
  while (!que.empty()) {
    auto tmp = que.top();
    que.pop();
    int v = tmp.second;
    long long dis = tmp.first;
    if (dis > dp[v])
      continue;
    long long height = calc_height(v, dp[v]);
    for (auto e : G[v]) {
      int nv = e.first;
      long long w = e.second;
      if (chmin(dp[nv], dp[v] + calc_dist(v, nv, height, w))) {
        que.push({dp[nv], nv});
      }
    }
    long long h = calc_height(N - 1, dp[N - 1]);
    long long res = dp[N - 1] + (H[N - 1] - h);
    cout << (res < INF ? res : -1) << endl;
  }
}
