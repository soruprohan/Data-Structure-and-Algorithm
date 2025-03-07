#include<bits/stdc++.h>
using namespace std;

int vis[100];

bool dfs(vector<int> g[],int node,int parent)
{
    vis[node]=1;

    for(auto it: g[node]){
        if(!vis[it]){
            if(dfs(g,it,node)) return true;
        }
        else if(it!=parent)
            return true;
    }
    return false;
}

bool check(vector<int> g[],int n)
{
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(dfs(g,i,-1)) return true;
        }
    }
    return false;
}

int main()
{
     int n,m;
    cin>>n>>m;
    vector<int> g[n+1];

    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    cout<<check(g,n)<<endl;
}


