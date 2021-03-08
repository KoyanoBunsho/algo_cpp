#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
using Graph = vector<vector<int>>;

vector<bool> seen;
void dfs(const Graph &G, int v){
    seen[v] = true;
    for (auto next_v: G[v]){
        if (seen[next_v]) continue;
        dfs(G, next_v);
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    Graph G(N);
    rep(i, M){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    seen.assign(N, false);
    dfs(G, 0);
}