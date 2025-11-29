#include <iostream>
using namespace std;

#define MAX 100
int adj[MAX][MAX];

int main(){
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter adjacency matrix (0 for no edge):\n";
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            cin >> adj[i][j];

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    int dist[MAX], vis[MAX];
    for(int i=0;i<V;i++){
        dist[i]=9999;
        vis[i]=0;
    }
    dist[src]=0;

    for(int c=0;c<V-1;c++){
        int u=-1, minVal=9999;
        for(int i=0;i<V;i++)
            if(!vis[i] && dist[i]<minVal){
                minVal=dist[i];
                u=i;
            }
        vis[u]=1;

        for(int v=0;v<V;v++)
            if(adj[u][v]!=0 && dist[u]+adj[u][v]<dist[v])
                dist[v]=dist[u]+adj[u][v];
    }

    cout << "Distances from source:\n";
    for(int i=0;i<V;i++)
        cout << dist[i] << " ";
    cout << endl;

    return 0;
}
