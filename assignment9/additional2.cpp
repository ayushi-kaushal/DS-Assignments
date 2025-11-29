#include <iostream>
using namespace std;

#define MAX 50

int main(){
    int m,n;
    cout << "Enter grid rows and columns: ";
    cin >> m >> n;

    int grid[MAX][MAX], dist[MAX][MAX], vis[MAX][MAX]={0};
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            cin >> grid[i][j];
            dist[i][j]=9999;
        }

    dist[0][0]=grid[0][0];

    for(int step=0;step<m*n;step++){
        int minVal=9999, x=-1,y=-1;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(!vis[i][j] && dist[i][j]<minVal){
                    minVal=dist[i][j];
                    x=i; y=j;
                }
        if(x==-1) break;
        vis[x][y]=1;

        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};

        for(int k=0;k<4;k++){
            int nx=x+dx[k], ny=y+dy[k];
            if(nx>=0 && nx<m && ny>=0 && ny<n)
                if(dist[nx][ny]>dist[x][y]+grid[nx][ny])
                    dist[nx][ny]=dist[x][y]+grid[nx][ny];
        }
    }

    cout << "Minimum cost from (0,0) to ("<<m-1<<","<<n-1<<"): " << dist[m-1][n-1] << endl;
    return 0;
}
