#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)

int n, p, A[1010];
int ans = 1000000007;

bool solve(int border){
    int current_cnt = 0;
    rep(i, n){
        if (A[i] > border) current_cnt += 1;
        else current_cnt = 0;
        if (current_cnt >= p) return false;
    }
    return true;
}

int main(){
    cin >> n >> p;
    rep(i, n) cin >> A[i];
    rep(i, n){
        if(solve(A[i])) ans = min(ans, A[i]);
    }
    cout << ans << endl;
    return 0;
}