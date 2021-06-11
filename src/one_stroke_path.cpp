#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
int ab[10][10];
int main() {
  int N, M;
  cin >> N >> M;
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a;
    b;
    ab[a][b] = 1;
    ab[b][a] = 1;
  }
  int ans = 0;
  vector<int> perm(N);
  rep(i, N) { perm[i] = i + 1; };
  do {
    if (perm[0] == 1) {
      bool flg = true;
      rep(i, N - 1) {
        if (ab[perm[i]][perm[i + 1]] == 0)
          flg = false;
      }
      if (flg)
        ans++;
    }
  } while (next_permutation(perm.begin(), perm.end()));
  cout << ans << endl;
  return 0;
}
