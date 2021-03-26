#include<bits/stdc++.h>
using namespace std;

int N, K, A[1010];
int dp[10010];

int main(){
    cin >> N >> K;
    for(int i=1; i<=N; i++)cin >> A[i];
    dp[0] = 1;
    for(int i=1; i<=N; i++){
        for(int j=K-A[i]; j>=0; j--){
            if(dp[j]==1)dp[j+A[i]]=1;
        }
    }
    if(dp[K]==1)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}