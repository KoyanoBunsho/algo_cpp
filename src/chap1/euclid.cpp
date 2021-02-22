#include<bits/stdc++.h>
using namespace std;

int euclid(int x, int y){
    if (y == 0) return x;
    else return euclid(y, x%y);
}

int main(){
    int x, y;
    cin >> x >> y;
    int ans = euclid(x, y);
    cout << ans << endl;
    return 0;
}