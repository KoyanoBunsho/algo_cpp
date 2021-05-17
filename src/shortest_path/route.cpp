#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
template <class T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

using DD = double;
const DD EPS = 1e-10;
const DD PI = acosl(-1.0);
DD torad(int deg) { return (DD)(deg)*PI / 180; }
DD todeg(DD ang) { return ang * 180 / PI; }

struct Point {
  DD x, y;
  Point(DD x = 0.0, DD y = 0.0) : x(x), y(y) {}
  friend ostream &operator<<(ostream &s, const Point &p) {
    return s << '(' << p.x << ", " << p.y << ')';
  }
};
inline Point operator+(const Point &p, const Point &q) {
  return Point(p.x + q.x, p.y + q.y);
}
inline Point operator-(const Point &p, const Point &q) {
  return Point(p.x - q.x, p.y - q.y);
}
inline Point operator*(const Point &p, DD a) { return Point(p.x * a, p.y * a); }
inline Point operator*(DD a, const Point &p) { return Point(a * p.x, a * p.y); }
inline Point operator*(const Point &p, const Point &q) {
  return Point(p.x * q.x - p.y * q.y, p.x * q.y + p.y * q.x);
}
inline Point operator/(const Point &p, DD a) { return Point(p.x / a, p.y / a); }
inline Point conj(const Point &p) { return Point(p.x, -p.y); }
inline Point rot(const Point &p, DD ang) {
  return Point(cos(ang) * p.x - sin(ang) * p.y,
               sin(ang) * p.x + cos(ang) * p.y);
}
inline Point rot90(const Point &p) { return Point(-p.y, p.x); }
inline DD cross(const Point &p, const Point &q) {
  return p.x * q.y - p.y * q.x;
}
inline DD dot(const Point &p, const Point &q) { return p.x * q.x + p.y * q.y; }
inline DD norm(const Point &p) { return dot(p, p); }
inline DD abs(const Point &p) { return sqrt(dot(p, p)); }
inline DD amp(const Point &p) {
  DD res = atan2(p.y, p.x);
  if (res < 0)
    res += PI * 2;
  return res;
}

const long long INF = 1LL << 60;
int main() {
  int N, M;
  cin >> N >> M;
  vector<Point> vp(N);
  rep(i, N) cin >> vp[i].x >> vp[i].y;
  auto isvalid = [&](int pv, int v, int nv) -> bool {
    DD pang = amp(vp[pv] - vp[v]), nang = amp(vp[nv] - vp[v]);
    DD dif = abs(pang - nang);
    if (dif < PI / 2 - EPS)
      return false;
    else
      return true;
  };
  using pint = pair<int, int>;
  using Edge = pair<int, long long>;
  using Graph = vector<vector<Edge>>;
  Graph G(N);
  rep(i, M) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    G[u].emplace_back(v, w), G[v].emplace_back(u, w);
  }
  int s = 0;
  vector<vector<long long>> dp(N, vector<long long>(N, INF));
  priority_queue<pair<long long, pint>, vector<pair<long long, pint>>,
                 greater<pair<long long, pint>>>
      que;
  for (auto e : G[s]) {
    dp[s][e.first] = e.second;
    que.push(make_pair(dp[s][e.first], pint(s, e.first)));
  }
  while (!que.empty()) {
    auto tmp = que.top();
    que.pop();
    long long dis = tmp.first;
    int pv = tmp.second.first, v = tmp.second.second;
    if (dis > dp[pv][v])
      continue;
    for (auto e : G[v]) {
      int nv = e.first;
      if (!isvalid(pv, v, nv))
        continue;
      if (chmin(dp[v][nv], dp[pv][v] + e.second)) {
        que.push(make_pair(dp[v][nv], pint(v, nv)));
      }
    }
  }
  long long res = INF;
  rep(v, N) chmin(res, dp[v][1]);
  cout << (res < INF ? res : -1) << endl;
}
