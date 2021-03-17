#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
const int INF = 1<<29;

int n, A;
int a[110];
int dp[110][10010];

int main(){
    cin >> n >> A;
    rep(i, n) cin >> a[i];
    rep(i, 110){
        rep(j, 10010){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    rep(i, n){
        rep(j, A+1){
            if (j>=a[i]) dp[i+1][j] = min(dp[i][j-a[i]]+1, dp[i][j]);
            else dp[i+1][j] = dp[i][j];
        }
    }
    if (dp[n][A] < INF) cout << dp[n][A] << endl;
    else cout << -1 << endl;
    return 0;
}