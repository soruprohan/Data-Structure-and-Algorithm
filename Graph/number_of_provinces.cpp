#include<bits/stdc++.h>
using namespace std;

bool vis[100];
vector<int> DFS,BFS;

void print(vector<int> v)
{
    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
}

void dfs(vector<int>g[],int node)
{
    if(vis[node])
        return;
    vis[node]=true;
    DFS.push_back(node);

    for(auto it: g[node]){
        dfs(g,it);
    }
    return;
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

    int ct=0;
    for(int i=1; i<=n; i++){

        if(!vis[i]){
            dfs(g,i);
            ct++;
        }
    }
    cout<<"The number of provinces is:"<<ct<<endl;

}
