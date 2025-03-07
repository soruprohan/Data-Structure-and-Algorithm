#include<bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>>&grid,pair<int,int>source,pair<int,int>destination)
{
    queue<pair<int,pair<int,int>>> q;
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dis(n,vector<int>(m,1e9));
    dis[source.first][source.second]=0;
    q.push({0,{source.first,source.second}});

    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};

    while(!q.empty()){
        int dist=q.front().first;
        int r=q.front().second.first;
        int c=q.front().second.second;
        q.pop();

        for(int i=0; i<4; i++){
            int nrow=r+dr[i];
            int ncol=c+dc[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
               && grid[nrow][ncol]==1 && dis[nrow][ncol]> dist+1){

                dis[nrow][ncol]=dist+1;
                if(nrow==destination.first && ncol==destination.second)
                    return dis[nrow][ncol];

                q.push({dis[nrow][ncol],{nrow,ncol}});
               }
        }
    }

    return -1;
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

    pair<int,int> source={0,1},destination={2,2}; //nije theke nisi striver er example theke

    int dist=shortestPath(grid,source,destination);
    cout<<dist<<endl;
}

