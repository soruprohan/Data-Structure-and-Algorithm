#include<bits/stdc++.h>

using namespace std;
const int N=10000;

vector<int> g[N];
bool vis[N];

void dfs(int vertex)
{
    vis[vertex]=true;
    for(int child : g[vertex])
    {
        if(vis[child]==true)
            continue;
        dfs(child);
    }

}

int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0; i<e; i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    int ct=0;
    for(int i=0; i<n; i++){
        if(vis[i]==true)
            continue;

            dfs(i);
            ct++;

    }
    cout<<ct<<endl;
}
