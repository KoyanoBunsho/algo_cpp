#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
  int n;
  cin >> n;
  set<int> s;
  rep(i, n) {
    int b;
    cin >> b;
    s.insert(b);
  }
  cout << s.size() << endl;
  return 0;
}
