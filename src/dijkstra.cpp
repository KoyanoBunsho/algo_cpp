#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define V 9

int minDistance(int dist[], bool sptSet[]){
    int min = INT_MAX, min_index;
    rep(v, V){
        if(sptSet[v]==false && dist[v]<=min) min = dist[v], min_index=v;
    }
    return min_index;
}

int printSolution(int dist[], int n){
    rep(i, V) cout << i << " " << dist[i] << endl;
    return 0;
}

void dijkstra(int graph[V][V], int src){
    int dist[V];
    bool sptSet[V];
    rep(i, V) dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;
    rep(count, V-1){
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        rep(v, V){
            if(sptSet[v] && graph[u][v] && dist[u]!=INT_MAX
            && dist[u]+graph[u][v]<dist[v]) dist[v] = dist[u]+graph[u][v];
        }
    }
    printSolution(dist, V);
}

int main(){
    int graph[V][V]={{0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0}};
    dijkstra(graph, 0);
    return 0;
}