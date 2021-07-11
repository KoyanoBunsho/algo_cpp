#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define P pair<int, int>
#define ll long long

const int MAX = 210000;
const ll INF = 1LL << 59;
vector<vector<P>> G, rG;
ll a[MAX];
int n, m, t;

vector<ll> Dijkstra(const vector<vector<P>> &G) {
  vector<ll> res(n, INF);
  res[0] = 0;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      que;
  que.push(make_pair(0, 0));
  while (!que.empty()) {
    ll dis = que.top().first;
    int v = que.top().second;
    que.pop();
    if (res[v] > dis)
      continue;
    rep(i, G[v].size()) {
      int nv = G[v][i].first;
      int w = G[v][i].second;
      if (res[nv] > dis + w) {
        res[nv] = dis + w;
        que.push(make_pair(dis + w, nv));
      }
    }
  }
  return res;
}

int main() {
  cin >> n >> m >> t;
  G.clear();
  rG.clear();
  rep(i, n) cin >> a[i];
  G.resize(n);
  rG.resize(n);
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    --a;
    --b;
    G[a].push_back(make_pair(b, c));
    rG[b].push_back(make_pair(a, c));
  }
  vector<ll> dg = Dijkstra(G);
  vector<ll> drg = Dijkstra(rG);
  ll res = 0;
  rep(i, n) {
    ll ct = dg[i] + drg[i];
    if (t < ct)
      continue;
    ll rt = t - ct;
    ll tmp = rt + a[i];
    if (res < tmp)
      res = tmp;
  }
  cout << res << endl;
  return 0;
}
