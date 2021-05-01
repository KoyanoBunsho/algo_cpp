#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long

int N, Q;

template <class T> struct BIT {
  vector<T> bit;
  BIT(int N) : bit(N + 1) { fill(bit.begin(), bit.end(), 0); }
  void add(int a, T w) {
    for (int x = a; x < (int)bit.size(); x += x & -x) {
      bit[x] += w;
    }
  }
  T sum(int a) {
    T ret = 0;
    for (int x = a; x > 0; x -= x & -x) {
      ret += bit[x];
    }
    return ret;
  }
};

int main() {
  cin >> N >> Q;
  BIT<ll> tree(N);
  rep(i, N) {
    ll a;
    cin >> a;
    tree.add(i + 1, a);
  }
  rep(i, Q) {
    ll q0, q1, q2;
    cin >> q0 >> q1 >> q2;
    if (q0 == 0) {
      tree.add(q1 + 1, q2);
    } else {
      cout << tree.sum(q2) - tree.sum(q1) << endl;
    }
  }
  return 0;
}
