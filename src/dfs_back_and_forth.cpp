#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < n; i++)

vector<bool> seen;
vector<int> first_order;
vector<int> last_order;

void dfs(const Graph &G, int v, int &first_ptr, int &last_ptr) {
  first_order[v] = first_ptr++;
  seen[v] = true;
  for (auto next_v : G[v]) {
    if (seen[next_v])
      continue;
    dfs(G, next_v, first_ptr, last_ptr);
  }
  last_order[v] = last_ptr++;
}

int main() {
  int n, m;
  cin >> n >> m;
  Graph G(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  seen.assign(n, false);
  first_order.resize(n);
  last_order.resize(n);
  int first_ptr = 0;
  int last_ptr = 0;
  dfs(G, 0, first_ptr, last_ptr);
  rep(v, n) { cout << v << ": " << first_order[v] << last_order[v] << endl; }
}
