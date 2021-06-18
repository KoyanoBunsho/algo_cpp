#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

string S, T;

int main() {
  cin >> S >> T;
  for (int i = S.size(); i--;) {
    if (i + T.size() > S.size())
      continue;
    bool flg = true;
    rep(j, T.length()) {
      if (!(S[i + j] == T[j] || S[i + j] == '?')) {
        flg = false;
        break;
      }
    }
    if (flg) {
      rep(j, T.size()) {
        if (S[i + j] == '?')
          S[i + j] = T[j];
      }
      rep(j, S.size()) {
        if (S[j] == '?')
          S[j] = 'a';
      }
      cout << S << endl;
      return 0;
    }
  }
  cout << "UNRESTORABLE" << endl;
  return 0;
}
