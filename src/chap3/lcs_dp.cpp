#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)

int dp[1010][1010];

int main(){
    string s, t;
    cin >> s >> t;
    memset(dp, 0, sizeof(dp));
    rep(i, s.size()){
        rep(j, t.size()){
            if (s[i] == t[i])dp[i+1][j+1] = max(dp[i][j] + 1, dp[i+1][j+1]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i+1][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j+1]);
        }
    }
    cout << dp[s.size()][t.size()] << endl;
    return 0;
}