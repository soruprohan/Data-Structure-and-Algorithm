#include<bits/stdc++.h>
using namespace std;

int rotten_oranges(vector<vector<int>> &grid)
{
    int n=grid.size();  //row
    int m=grid[0].size(); //column

    queue<pair<pair<int,int>,int>> q;
    vector<vector<int>>vis(n,vector<int>(m,0));
    int cntfresh=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                vis[i][j]=2;
            }
            if(grid[i][j]==1)
                cntfresh++;
        }
    }

    int cnt=0;
    int tm=0;
    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int t=q.front().second;
        tm=t;
        //tm=max(tm,t);
        q.pop();

        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};

        for(int i=0; i<4; i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
               && grid[nrow][ncol]==1 && vis[nrow][ncol]!=2){

                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                    cnt++;
               }
        }
    }

    if(cnt!=cntfresh) return -1;
    else
        return tm;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m,0));

     for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }

    int time=rotten_oranges(grid);
    cout<<time<<endl;
}
