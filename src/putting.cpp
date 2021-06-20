#include <bits/stdc++.h>
using namespace std;
int n, w, d[55];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    d[i] = 999999;
  for (int i = 0; i < n; i++) {
    cin >> w;
    int x = 1000000, id;
    for (int j = 0; j < n; j++) {
      if (d[j] >= w && x > d[j]) {
        x = d[j];
        id = j;
      }
    }
    d[id] = w;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++)
    cnt += d[i] < 999999;
  cout << cnt << endl;
}
