#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)

void bucketSort(float arr[], int n){
    vector<float> b[n];
    rep(i, n){
        int bi = n*arr[i];
        b[bi].push_back(arr[i]);
    }
    rep(i, n) sort(b[i].begin(), b[i].end());
    int index = 0;
    rep(i, n){
        rep(j, b[i].size()) arr[index++] = b[i][j];
    }
}

int main(){
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr, n);
    rep(i, n) cout << arr[i] << "";
    return 0;
}