#include<bits/stdc++.h>

using namespace std;
const int N=10000;

vector<int> g[N];
bool vis[N];

bool dfs(int vertex,int par)
{
    vis[vertex]=true;
    bool IsLoopExist=false;

    for(int child : g[vertex])
    {
        if(vis[child]==true && child==vertex)
            continue;
        if(vis[child])
            return true;

        IsLoopExist=IsLoopExist | dfs(child,vertex);
    }
    return IsLoopExist;
}

int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=1; i<=e; i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    bool IsLoopExist=false;
    for(int i=1; i<=n; i++){
        if(vis[i]==true)
            continue;

            if(dfs(i,0)){
                IsLoopExist=true;
            }
    }
    cout<<IsLoopExist<<endl;
}
