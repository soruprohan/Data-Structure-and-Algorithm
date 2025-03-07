#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &v)
{
    for(auto it: v){
        for(auto it2: it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
}

void dfs(vector<vector<int>> &grid,int row,int col,int inicolor,int newcolor,
         vector<vector<int>> &ans)
{
    int n=grid.size();
    int m=grid[0].size();
    ans[row][col]=newcolor;

    for(int delrow=-1; delrow<=1; delrow++){
        for(int delcol=-1; delcol<=1; delcol++){
            if(delrow!=0 && delcol!=0)
                continue;
            int nrow=row+delrow;
            int ncol=col+delcol;

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
               && grid[nrow][ncol]==inicolor && ans[nrow][ncol]!=newcolor){
                dfs(grid,nrow,ncol,inicolor,newcolor,ans);
               }
        }
    }
}

vector<vector<int>> floodfill(vector<vector<int>> &grid,int sr,int sc,int inicolor,int newcolor)
{
    int n=grid.size();
    int m=grid[0].size();

    vector<vector<int>> ans(n,vector<int>(m,0));

    dfs(grid,sr,sc,inicolor,newcolor,ans);
    return ans;
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
    int sr,sc,inicolor,newcolor;
    cout<<"Enter sr,sc,newcolor: ";
    cin>>sr>>sc>>newcolor;
    inicolor=grid[sr][sc];

    vector<vector<int>> ans=floodfill(grid,sr,sc,inicolor,newcolor);
    print(ans);
}
