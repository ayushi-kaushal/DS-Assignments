#include <iostream>
using namespace std;

struct Edge {
    int u,v,w;
};

int parent[100];

int findParent(int x){
    if(parent[x]==x) return x;
    return parent[x]=findParent(parent[x]);
}

void merge(int a,int b){
    a=findParent(a);
    b=findParent(b);
    parent[b]=a;
}

int main(){
    int V,E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Edge edges[100];
    cout << "Enter edges (u v w):\n";
    for(int i=0;i<E;i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    // Initialize parents
    for(int i=0;i<V;i++) parent[i]=i;

    // Simple Bubble Sort for weight
    for(int i=0;i<E-1;i++)
        for(int j=0;j<E-1-i;j++)
            if(edges[j].w > edges[j+1].w){
                Edge temp = edges[j];
                edges[j]=edges[j+1];
                edges[j+1]=temp;
            }

    cout << "Kruskal MST edges:\n";
    for(int i=0;i<E;i++){
        int pu = findParent(edges[i].u);
        int pv = findParent(edges[i].v);
        if(pu!=pv){
            cout << edges[i].u << " - " << edges[i].v << " (w=" << edges[i].w << ")\n";
            merge(pu,pv);
        }
    }
    return 0;
}
