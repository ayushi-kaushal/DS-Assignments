#include <iostream>
using namespace std;

#define MAX 100
int adj[MAX][MAX], visited[MAX];

void BFS(int start, int V){
    int q[MAX], front=0, rear=-1;
    visited[start]=1;
    q[++rear]=start;

    while(front<=rear){
        int node=q[front++];
        for(int i=0;i<V;i++)
            if(adj[node][i]==1 && visited[i]==0){
                visited[i]=1;
                q[++rear]=i;
            }
    }
}

int main(){
    int V,E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            adj[i][j]=0;

    cout << "Enter edges (u v):\n";
    for(int i=0;i<E;i++){
        int u,v;
        cin >> u >> v;
        adj[u][v]=1;
        adj[v][u]=1;
    }

    for(int i=0;i<V;i++) visited[i]=0;

    int count=0;
    for(int i=0;i<V;i++)
        if(visited[i]==0){
            count++;
            BFS(i,V);
        }

    cout << "Number of connected components: " << count << endl;
    return 0;
}
