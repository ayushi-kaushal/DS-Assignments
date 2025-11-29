#include <iostream>
using namespace std;

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int V, E;

void BFS(int start) {
    for(int i=0;i<V;i++) visited[i]=0;
    int q[MAX], front=0, rear=-1;
    visited[start]=1;
    q[++rear]=start;

    cout << "BFS: ";
    while(front <= rear){
        int node = q[front++];
        cout << node << " ";
        for(int i=0;i<V;i++){
            if(adj[node][i]==1 && visited[i]==0){
                visited[i]=1;
                q[++rear]=i;
            }
        }
    }
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
        adj[v][u]=1; // for undirected graph
    }

    int start;
    cout << "Enter starting vertex for BFS: ";
    cin >> start;

    BFS(start);
    return 0;
}
