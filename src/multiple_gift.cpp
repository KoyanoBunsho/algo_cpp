#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long

ll X, Y;

int main() {
  cin >> X >> Y;
  ll n = 0;
  while (X <= Y) {
    n++;
    X *= 2;
  }
  cout << n << endl;
  return 0;
}
