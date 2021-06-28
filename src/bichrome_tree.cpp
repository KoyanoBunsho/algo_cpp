#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define P pair<int, int>

int N;
vector<int> G[1000];
int X[1000];
bool ans;
P dfs(int u) {
  bitset<5001> now;
  now[0] = 1;
  int sum = 0;
  rep(i, G[u].size()) {
    P p = dfs(G[u][i]);
    sum += p.first + p.second;
    now = now << p.first | now << p.second;
  }
  int id = X[u];
  while (id >= 0 && !now[id])
    id--;
  if (id < 0)
    ans = 1;
  return {X[u], sum - id};
}

int main() {
  cin >> N;
  for (int i = 1; i < N; i++) {
    int p;
    cin >> p;
    G[p - 1].push_back(i);
  }
  rep(i, N) cin >> X[i];
  dfs(0);
  cout << (ans ? "IM" : "") << "POSSIBLE" << endl;
  return 0;
}
