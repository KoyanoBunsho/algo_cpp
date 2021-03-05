#include<bits/stdc++.h>
using namespace std;
#define V 4
#define INF 99999
#define rep(i, n) for(int i=0; i<n; i++)
void printSolution(int dist[][V]){
    rep(i, V){
        rep(j, V){
            if(dist[i][j]==INF) cout << "INF" << " ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

void floydWarshall(int graph[][V]){
    int dist[V][V], i, j, k;
    rep(i, V){
        rep(j, V){
            dist[i][j] = graph[i][j];
        }
    }
    rep(k, V){
        rep(i, V){
            rep(j, V){
                if(dist[i][k]+dist[j][j]<dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printSolution(dist);
}


int main(){
    int graph[V][V] = {{0, 5, INF, 10},
    {INF, 0, 3, INF}, {INF, INF, 0, 1},
    {INF, INF, INF, 0}};
    floydWarshall(graph);
    return 0;
}