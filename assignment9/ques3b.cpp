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

    int key[MAX], parent[MAX], selected[MAX];
    for(int i=0;i<V;i++){
        key[i]=9999;
        selected[i]=0;
    }
    key[0]=0;
    parent[0]=-1;

    for(int count=0;count<V-1;count++){
        int minVal=9999, u=-1;
        for(int i=0;i<V;i++)
            if(!selected[i] && key[i]<minVal){
                minVal=key[i];
                u=i;
            }
        selected[u]=1;

        for(int v=0;v<V;v++)
            if(adj[u][v]!=0 && !selected[v] && adj[u][v]<key[v]){
                key[v]=adj[u][v];
                parent[v]=u;
            }
    }

    cout << "Prim MST edges:\n";
    for(int i=1;i<V;i++)
        cout << parent[i] << " - " << i << " (w=" << adj[i][parent[i]] << ")\n";

    return 0;
}
