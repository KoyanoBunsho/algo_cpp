#include<bits/stdc++.h>
using namespace std;
const long long INF = 1LL<<60;
#define rep(i, n) for(int i=0; i<n; i++)

int LIS(const vector<long long> &a){
    int N = (int)a.size();
    vector<long long> dp(N, INF);
    rep(i, N){
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        *it = a[i];
    }
    return lower_bound(dp.begin(), dp.end(), INF)-dp.begin();
}

int main(){
    int N; cin >> N;
    vector<long long> a(N);
    rep(i, N)cin >> a[i];
    cout << LIS(a) << endl;
}