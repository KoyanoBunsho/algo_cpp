#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
const int INF = 1<<29;

int dp[1010][1010];
int c[1010][1010];
int m, n;

int main(){
    cin >> m >> n;
    rep(i, m){
        rep(j, n){
            cin >> c[i][j];
        }
    }
    rep(i, m){
        rep(j, n){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    rep(i, m){
        rep(j, n){
            dp[i+1][j+1] = min(dp[i][j], dp[i+1][j+1]);
            dp[i+1][j+1] = min(dp[i][j+1], dp[i+1][j+1]);
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j+1]) + c[i][j];
        }
    }
    cout << dp << dp[m][n] << endl;
    return 0;
}