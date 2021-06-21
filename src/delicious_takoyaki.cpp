#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
  int T, N;
  cin >> T >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  int M;
  cin >> M;
  vector<int> B(M);
  rep(i, N) cin >> B[i];
  bool flg = true;
  int i, j;
  for (; i < N && j < M;) {
    if (A[i] <= B[j] && B[j] <= A[i] + T) {
      ++i, ++j;
    } else if (B[j] < A[i]) {
      flg = false;
      break;
    } else {
      ++i;
    }
  }
  if (flg && j == M)
    cout << "yes" << endl;
  else
    cout << "no" << endl;
  return 0;
}
