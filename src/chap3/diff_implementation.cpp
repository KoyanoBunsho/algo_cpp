#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
const int INF = 1<<29;

int n, m;
string S, T;
int dp[1010][1010];

int main(){
    cin >> n >> m >> S >> T;
    rep(i, 1010){
        rep(j, 1010){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for(int i=-1; i<(int)S.size(); ++i){
        for(int j=-1; j<(int)T.size(); ++j){
            if (i==-1 && j==-1)continue;
            if(j>=0 && j>=0){
                if (S[i]==T[j])dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
                else dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+1);
            }
            if (i>=0)dp[i+1][j+1]=min(dp[i+1][j+1], dp[i][j+1]+1);
            if (j>=0)dp[i+1][j+1]=min(dp[i+1][j+1], dp[i+1][j]+1);
        }
    }
    cout << dp[S.size()][T.size()] << endl;
    return 0;
}