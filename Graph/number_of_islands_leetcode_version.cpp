#include<bits/stdc++.h>
using namespace std;

void bfs(int row,int col,vector<vector<char>>& grid,int vis[305][305])
{
    queue<pair<int,int>> q;
    q.push({row,col});
    vis[row][col]=1;

    int m=grid.size();
    int n=grid[0].size();

    while(!q.empty()){

          row=q.front().first;
          col=q.front().second;
          q.pop();

        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                if(i!=0 && j!=0)
                    continue;
                int nrow=row+i;
                int ncol=col+j;

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n &&
                    !vis[nrow][ncol] && grid[nrow][ncol]=='1'){

                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                }
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int vis[305][305]={0};

        int ct=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    bfs(i,j,grid,vis);
                    ct++;
                }
            }
        }
        return ct;
}


int main()
{
    int row,col;
    cin>>row>>col;

    vector<vector<char>>grid(row,vector<char>(col,'0'));

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            char c;
            cin>>c;
            grid[i][j]=c;
        }
    }
    cout<<numIslands(grid)<<endl;
}

