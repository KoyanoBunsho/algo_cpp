#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

typedef int FLOW;
const int MAX_V = 100;
const FLOW INF = 1000000007;

struct Edge {
  int rev, from, to;
  FLOW cap, icap;
  Edge(int r, int f, int t, FLOW c) : rev(r), from(f), to(t), cap(c), icap(c) {}
  friend ostream &operator<<(ostrream &s, const Edge &E) {
    if (E.cap > 0)
      return s << E.from << "->" << E.to << '(' << E.cap << ')';
    else
      return s;
  }
};

struct Graph {
  int V;
  vector<Edge> list[MAX_V];
  Graph(int n = 0) : V(n) { rep(i, MAX_V) list[i].clear(); }
  void init(int n = 0) {
    V = n;
    rep(i, MAX_V) list[i].clear();
  }
  void resize(int n = 0) { V = n; }
  void reset() { rep(i, V) rep(j, list[i].size()) list[i][j].icap; }
  inline vector<Edge> &operator[](int i) { return list[i]; }
  Edge &redge(Edge e) {
    if (e.from != e.to)
      return list[e.to][e.rev];
    else
      return list[e.to][e.rev + 1];
  }
  void addedge(int from, int to, FLOW cap) {
    list[from].push_back(Edge((int)list[to].size(), from, to, cap));
    list[to].push_back(Edge((int)list[from].size() - 1, to, from, 0));
  }
};

static int level[MAX_V];
static int iter[MAX_V];

void dibfs(Graph &G, int s) {
  rep(i, MAX_V) level[i] = -1;
  level[s] = 0;
  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    rep(i, G[v].size()) {
      Edge &e = G[v][i];
      if (level[e.to] < 0 && e.cap > 0) {
        level[e.to] = level[v] + 1;
        que.push(e.to);
      }
    }
  }
}

FLOW didfs(Graph &G, int v, int t, FLOW f) {
  if (v == t)
    return f;
  for (int &i = iter[v]; i < G[v].size(); i++) {
    Edge &e = G[v][i], &re = G.redge(e);
    if (level[v] < level[e.to] && e.cap > 0) {
      FLOW d = didfs(G, e.to, t, min(f, e.cap));
      if (d > 0) {
        e.cap -= d;
        re.cap += d;
        return d;
      }
    }
  }
  return 0;
}

FLOW Dinic(Graph &G, int s, int t) {
  FLOW res = 0;
  while (true) {
    dibfs(G, s);
    if (level[t] < 0)
      return res;
    memset(iter, 0, sizeof(iter));
    FLOW flow;
    while ((flow = didfs(G, s, t, INF)) > 0) {
      res += flow;
    }
  }
}

int main() {
  int men[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int women[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int NUM_MEN = 0, NUM_WOMEN = 0;
  cin >> NUM_MEN >> NUM_WOMEN;
  Graph G(NUM_MEN + NUM_WOMEN + 2);
  int S_node = NUM_MEN + NUM_WOMEN;
  int T_node = NUM_MEN + NUM_WOMEN + 1;
  rep(i, NUM_MEN) {
    rep(j, NUM_WOMEN) {
      char isok;
      cin >> isok;
      if (isok == 'o') {
        G.addedge(i, j + NUM_MEN, 1);
      }
    }
  }
  rep(i, NUM_MEN) { G.addedge(S_node, i, 1); }
  rep(j, NUM_WOMEN) { G.addedge(j + NUM_MEN, T_node, 1); }
  FLOW res = Dinic(G, S_node, T_node);
  cout << "Max Size of Matching:" << res << endl;
  rep(i, NUM_MEN) {
    for (auto e : G[i]) {
      if (e.icap == 1 && e.cap == 0) {
        cout << "Man " << men[i] << " and "
             << "Woman " << women[e.to - NUM_MEN] << " are matched" << endl;
      }
    }
  }
  return 0;
}
