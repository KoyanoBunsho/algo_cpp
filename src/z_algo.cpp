#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

vector<int> Zalgo(string str) {
  int n = str.size();
  vector<int> a(n, 0);
  int from = -1;
  int last = 1;
  for (int i = 1; i < n; i++) {
    int &same = a[i];
    if (from != -1) {
      same = min(a[i - from], last - i);
      same = max(0, same);
    }

    while (i + same < str.size() && str[same] == str[i + same])
      same++;
    if (last < i + same) {
      last = i + same;
      from = i;
    }
  }
  a[0] = n;
  return a;
}

int main() {
  string str;
  cin >> str;
  auto a = Zalgo(str);
  for (auto num : a) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
