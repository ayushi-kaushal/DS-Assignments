#include <iostream>
using namespace std;

#define MAX 50

int grid[MAX][MAX];
int M,N;

void DFS(int x,int y){
    if(x<0 || y<0 || x>=M || y>=N || grid[x][y]==0) return;
    grid[x][y]=0;
    DFS(x+1,y);
    DFS(x-1,y);
    DFS(x,y+1);
    DFS(x,y-1);
}

int main(){
    cout << "Enter grid rows and columns: ";
    cin >> M >> N;

    cout << "Enter grid (1=land,0=water):\n";
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            cin >> grid[i][j];

    int count=0;
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            if(grid[i][j]==1){
                count++;
                DFS(i,j);
            }

    cout << "Number of islands: " << count << endl;
    return 0;
}
