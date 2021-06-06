#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

const int MAX_N = 105;
const int MAX_M = 10005;
vector<bool> visited(MAX_N);
// 隣接行列か隣接リストで管理
vector<int> graph[MAX_N];

bool dfs(int s, int p) {
  visited[s] = true;
  bool ans = true;
  for (auto s_sub : graph[s]) {
    if (s_sub != p) {
      if (visited[s_sub])
        ans = false;
      else if (!dfs(s_sub, s))
        ans = false;
    }
  }
  return ans;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> u(M), v(M);
  memset(graph, 0, sizeof(graph));
  rep(i, M) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  int ans = 0;
  for (int i = 1; i < N; i++) {
    if (!visited[i] && dfs(i, -1))
      ans++;
  }
  cout << ans << endl;
  return 0;
}
