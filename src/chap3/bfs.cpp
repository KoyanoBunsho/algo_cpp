#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, N) for(int i=0; i<N; i++)

int main(){
    int N, M;
    cin >> N >> M;
    Graph G(N);
    rep(i, M){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> dist(N, -1);
    queue<int> que;
    dist[0] = 0;
    que.push(0);
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for (int nv:G[v]){
            if (dist[nv]!=-1)continue;
            dist[nv] = dist[v]+1;
            que.push(nv);
        }
    }
    rep(v, N) cout << v << ": " << dist[v] << endl;
    return 0;
}