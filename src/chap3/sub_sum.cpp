#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)

int n, A;
int a[110];

bool dp[110][10010];

int main(){
    cin >> n >> A;
    rep(i, n) cin >> a[i];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;
    rep(i, n){
        rep(j, A+1){
            dp[i+1][j] |= dp[i][j];
            if(j>=a[i])dp[i+1][j] |= dp[i][j-a[i]];
        }
    }
    if(dp[n][A])cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}