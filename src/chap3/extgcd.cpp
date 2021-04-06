#include<bits/stdc++.h>
using namespace std;

long long extGCD(long long a, long long b, long long &x, long long &y){
    if(b==0){
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

int main(){
    long long x, y;
    extGCD(111, 30, x, y);
    cout << x << ", " << y << endl;
}