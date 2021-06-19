#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int N, K;
string S;

int resrem[30], Srem[30];

string solve() {
  string res = "";
  memset(Srem, 0, sizeof(Srem));
  memset(resrem, 0, sizeof(resrem));
  rep(i, N) Srem[(int)(S[i] - 'a')]++, resrem[(int)(S[i] - 'a')]++;
  rep(i, N) {
    char c = '{';
    rep(j, 26) {
      if (resrem[j] == 0)
        continue;
      Srem[(int)(S[i] - 'a')]--;
      resrem[j]--;
      int mindif = 0;
      rep(k, 26) { mindif += abs(Srem[k] - resrem[k]); }
      mindif /= 2;
      if (S[i] != (char)('a' + j))
        ++mindif;
      Srem[(int)(S[i] - 'a')]++;
      resrem[j]++;
      if (mindif <= K) {
        c = (char)('a' + j);
        break;
      }
    }
    Srem[(int)(S[i] - 'a')]--;
    resrem[(int)(c - 'a')]--;
    res += c;
    if (S[i] != c)
      --K;
  }
  return res;
}

int main() {
  cin >> N >> K;
  cin >> S;
  cout << solve() << endl;
  return 0;
}
