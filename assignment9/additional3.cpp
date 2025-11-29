#include <iostream>
using namespace std;

#define MAX 100
int adj[MAX][MAX];

int main(){
    int N,E,K;
    cout << "Enter number of nodes: ";
    cin >> N;
    cout << "Enter number of edges: ";
    cin >> E;

    for(int i=0;i<=N;i++)
        for(int j=0;j<=N;j++)
            adj[i][j]=0;

    cout << "Enter edges (u v w):\n";
    for(int i=0;i<E;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u][v]=w; // directed
    }

    cout << "Enter starting node K: ";
    cin >> K;

    int dist[MAX], vis[MAX]={0};
    for(int i=1;i<=N;i++) dist[i]=9999;
    dist[K]=0;

    for(int step=0;step<N;step++){
        int u=-1,minVal=9999;
        for(int i=1;i<=N;i++)
            if(!vis[i] && dist[i]<minVal){
                minVal=dist[i];
                u=i;
            }
        if(u==-1) break;
        vis[u]=1;

        for(int v=1;v<=N;v++)
            if(adj[u][v]!=0 && dist[v]>dist[u]+adj[u][v])
                dist[v]=dist[u]+adj[u][v];
    }

    int maxD=0;
    for(int i=1;i<=N;i++){
        if(dist[i]==9999){
            cout << "Some nodes cannot be reached. Return -1\n";
            return 0;
        }
        if(dist[i]>maxD) maxD=dist[i];
    }

    cout << "Network delay time: " << maxD << endl;
    return 0;
}
