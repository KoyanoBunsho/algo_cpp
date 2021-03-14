#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)

int n;
int a[100010];
int dp[10010];

int main(){
    cin >> n;
    rep(i, n) cin >> a[i];
    rep(i, n){
        dp[i+1] = max(dp[i], dp[i]+a[i]);
    }
    cout << dp[n] << endl;
}