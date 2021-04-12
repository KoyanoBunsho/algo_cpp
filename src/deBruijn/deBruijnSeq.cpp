#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)

unordered_set<string> seen;
vector<int> edges;

void dfs(string node, int &k, string &A){
    rep(i, k){
        string str = node + A[i];
        if(seen.find(str) == seen.end()){
            seen.insert(str);
            dfs(str.substr(1), k, A);
            edges.push_back(i);
        }
    }
}

string deBruijn(int n, int k, string A){
    seen.clear();
    edges.clear();
    string startingNode = string(n-1, A[0]);
    dfs(startingNode, k, A);
    string S;
    int l = pow(k, n);
    rep(i, l){
        S += A[edges[i]];
    }
    S += startingNode;
    return S;
}

int main(){
    int n = 3, k = 2;
    string A = "01";
    cout << deBruijn(n, k, A) << endl;
    return 0;
}