#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
template <class T> inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

int b[2][3], c[3][2];

typedef vector<string> FIELD;
map<FIELD, int> dp;

int calcNaotoScore(FIELD fi) {
  int res = 0;
  rep(i, 2) {
    rep(j, 3) {
      if (fi[i][j] == fi[i + 1][j])
        res += b[i][j];
    }
  }
  rep(i, 3) {
    rep(j, 2) {
      if (fi[i][j] == fi[i][j + 1])
        res += c[i][j];
    }
  }
  return res;
}

int rec(FIELD cur, int con) {
  if (con == 9) {
    return calcNaotoScore(cur);
  }
  if (dp.count(cur))
    return dp[cur];
  if (con % 2 == 0) {
    int res = 0;
    int pI = 0, pJ = 0;
    rep(i, 3) {
      rep(j, 3) {
        if (cur[i][j] != '?')
          continue;
        cur[i][j] = 'o';
        int tmp = rec(cur, con + 1);
        if (chmax(res, tmp)) {
          pI = i, pJ = j;
        }
        cur[i][j] = '?';
      }
    }
    return dp[cur] = res;
  } else {
    int res = 1 << 29;
    int pI = 0, pJ = 0;
    rep(i, 3) {
      rep(j, 3) {
        if (cur[i][j] != '?')
          continue;
        cur[i][j] = 'x';
        int tmp = rec(cur, con + 1);
        if (chmin(res, tmp)) {
          pI = i, pJ = j;
        }
        cur[i][j] = '?';
      }
    }
    return dp[cur] = res;
  }
}

int main() {
  cin >> b[0][0];
  int sum = b[0][0];
  rep(i, 2) {
    rep(j, 3) {
      if (i == 0 && j == 0)
        continue;
      cin >> b[i][j], sum += b[i][j];
    }
  }
  rep(i, 3) {
    rep(j, 2) { cin >> c[i][j], sum += c[i][j]; }
  }
  dp.clear();
  FIELD cur(3, "???");
  int res = rec(cur, 0);
  cout << res << endl;
  cout << sum - res << endl;
}
