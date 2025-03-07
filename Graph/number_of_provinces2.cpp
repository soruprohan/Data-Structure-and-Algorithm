#include<bits/stdc++.h>
using namespace std;

int vis[100];

void bfs(vector<int> g[],int start)
{
    queue<int> q;
    q.push(start);
    vis[start]=1;

    while(!q.empty()){
        int node=q.front();
        q.pop();

        for(auto it: g[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n+1][n+1];
    vector<int> g[n+1];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>a[i][j];
            if(a[i][j]==1){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    int ct=0;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            bfs(g,i);
            ct++;
        }
    }
    cout<<ct<<endl;
}

