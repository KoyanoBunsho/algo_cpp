#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
const int mod = 1000000009;
int n, A;
int a[110];
int dp[110][10010];
int main(){
    cin >> n >> A;
    rep(i, n) cin >> a[i];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    rep(i, n){
        rep(j, A+1){
            (dp[i+1][j] += dp[i][j]) %= mod;
            if (j>=a[i]) (dp[i+1][j] += dp[i][j-a[i]]) %= mod;
        }
    }
    cout << dp[n][A] << endl;
    return 0;
}