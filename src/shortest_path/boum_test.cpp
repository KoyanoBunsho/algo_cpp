#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

const int MAX_N = 105;
const int MAX_M = 10005;
bool visited[MAX_N];
vector<int> graph[MAX_N];

bool dfs(int s, int p) {
  visited[s] = true;
  bool ans = true;
  for (int s_sub : graph[s]) {
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
  rep(i, M) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  int ans = 0;
  rep(i, N) {
    if (!visited[i] && dfs(i, -1))
      ans++;
  }
  cout << ans << endl;
  return 0;
}
