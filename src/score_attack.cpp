#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long
bool chmin(ll &a, ll b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
const ll INF = 1LL << 60;

using Edge = pair<int, ll>;
int n, m;
vector<vector<Edge>> G;

int main() {
  cin >> n >> m;
  G.clear();
  G.resize(n);
  rep(i, m) {
    int a, b;
    ll w;
    cin >> a >> b >> w;
    --a;
    --b;
    G[a].push_back(Edge(b, -w));
  }
  vector<ll> dist(n, INF);
  bool negative = false;
  dist[0] = 0;
  rep(iter, n * 2 + 1) {
    rep(v, n) {
      if (dist[v] >= INF / 2)
        continue;
      for (auto e : G[v]) {
        if (chmin(dist[e.first], dist[v] + e.second)) {
          if (e.first == n - 1 && iter == n * 2)
            negative = true;
        }
      }
    }
  }
  if (!negative)
    cout << -dist[n - 1] << endl;
  else
    cout << "inf" << endl;
  return 0;
}
