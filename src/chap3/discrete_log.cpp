#include<bits/stdc++.h>
using namespace std;

long long modpow(long long a, long long n, long long mod){
    long long res = 1;
    while(n>0){
        if(n&1)res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long modinv(long long a, long long m){
    long long b = m, u = 1, v = 0;
    while(b){
        long long t = a/b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if(u<0) u += m;
    return u;
}

long long modlog(long long a, long long b, int m){
    a %= m, b %= m;
    long long lo = -1, hi = m;
    while(hi - lo > 1){
        long long mid = (lo+hi)/2;
        if(mid * mid >= m)hi = mid;
        else lo = mid;
    }
    long long sqrtM = hi;
    map<long long, long long> apow;
    long long amari = a;
    for(long long r=1; r<sqrtM; ++r){
        if(!apow.count(amari)) apow[amari] = r;
        (amari *= a) %= m;
    }
    long long A = modpow(modinv(a, m), sqrtM, m);
    amari = b;
    for(long long q = 0; q<sqrtM; ++q){
        if(amari == 1 && q>0) return q * sqrtM;
        else if(apow.count(amari)) return q * sqrtM + apow[amari];
        (amari *= A) %= m;
    }
    return -1;
}

int main(){
    const int MOD = 1000000007;
    for(long long a=2; a<=10; a++){
        for(long long b=1; b<=10; b++){
            cout << "log_" << a << "(" << b << ")" << modlog(a, b, MOD) << endl;
        }
    }
}