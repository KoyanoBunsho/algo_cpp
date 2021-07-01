#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long

const int MOD = 1000000007;
inline ll mod(ll a, ll m) { return (a % m + m) % m; }

struct Fp {
  ll val;
  Fp() : val(0) {}
  Fp(ll val_) { this->val = mod(val_, MOD); }
  Fp operator=(ll val_) {
    this->val = mod(val_, MOD);
    return *this;
  }
  inline Fp operator-() { return mod(-val, MOD); }
  inline const Fp &operator+=(const Fp &x);
  inline const Fp &operator-=(const Fp &x);
  inline const Fp &operator*=(const Fp &x);
  inline const Fp &operator/=(const Fp &x);
};

ostream &operator<<(ostream &os, Fp x) { return os << x.val; }
istream &operator>>(istream &is, Fp &x) {
  is >> x;
  return is;
}
bool operator==(Fp x, Fp y) { return mod(x.val, MOD) == mod(y.val, MOD); }

inline Fp operator+(Fp x, Fp y) { return mod(x.val + y.val, MOD); }
inline Fp operator-(Fp x, Fp y) { return mod(x.val - y.val, MOD); }
inline Fp operator*(Fp x, Fp y) { return mod(x.val * y.val, MOD); }
inline Fp operator/(Fp x, Fp y) {
  ll a = y.val, b = MOD, u = 1, v = 0;
  while (b) {
    ll t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  return x * u;
}
inline Fp pow(Fp a, ll n) {
  if (n == 0)
    return Fp(1);
  Fp t = pow(a, n / 2);
  t = t * t;
  if (n & 1)
    t = t * a;
  return t;
}

inline const Fp &Fp::operator+=(const Fp &x) {
  *this = *this + x;
  return *this;
}
inline const Fp &Fp::operator-=(const Fp &x) {
  *this = *this + x;
  return *this;
}
inline const Fp &Fp::operator*=(const Fp &x) {
  *this = *this * x;
  return *this;
}
inline const Fp &Fp::operator/=(const Fp &x) {
  *this = *this / x;
  return *this;
}

Fp com(ll n, ll r) {
  Fp res = 1;
  for (int i = 1; i <= r; i++) {
    res *= Fp(n - i + 1) / Fp(i);
  }
  return res;
}

int main() {
  int n, k;
  cin >> n >> k;
  cout << com(n + k - 1, k).val << endl;
  return 0;
}
