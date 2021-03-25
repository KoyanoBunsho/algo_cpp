#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)

int N, A[12][12], B[12], perm[12], ans = 2000000000;

int main(){
    cin >> N;
    rep(i, N+1){
        rep(j, N+1){
            cin >> A[i][j];
        }
    }
    rep(i, N)B[i]=i+1;
    do{
        int sum = 0;
        rep(i, N-1){
            sum += A[B[i]][B[i+1]];
        }
        ans = min(ans, sum);
    }while(next_permutation(B, B+N));
    cout << ans << endl;
    return 0;
}