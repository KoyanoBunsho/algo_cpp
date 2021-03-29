#include<bits/stdc++.h>
using namespace std;

int N, X, A[22];
bool flag = false;

int main(){
    cin >> N >> X;
    for(int i=1; i<=N; i++)cin >> A[i];
    for(int i=0; i<(1<<N); i++){
        int bit[30], sum=0;
        for(int j=0; j<N; j++){
            int Div = (1<<j);
            bit[j] = (i/Div)%2;
        }
        for(int j=0; j<N; j++)sum += A[j]*bit[j];
        if(sum==X)flag=true;
    }
    if(flag==true)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}