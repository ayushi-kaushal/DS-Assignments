#include <iostream>
using namespace std;

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int V, E;

void DFSUtil(int node){
    visited[node]=1;
    cout << node << " ";
    for(int i=0;i<V;i++)
        if(adj[node][i]==1 && visited[i]==0)
            DFSUtil(i);
}

void DFS(int start){
    for(int i=0;i<V;i++) visited[i]=0;
    cout << "DFS: ";
    DFSUtil(start);
    cout << endl;
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            adj[i][j]=0;

    cout << "Enter edges (u v) with 0-based vertices:\n";
    for(int i=0;i<E;i++){
        int u,v;
        cin >> u >> v;
        adj[u][v]=1;
        adj[v][u]=1; // undirected
    }

    int start;
    cout << "Enter starting vertex for DFS: ";
    cin >> start;

    DFS(start);
    return 0;
}
