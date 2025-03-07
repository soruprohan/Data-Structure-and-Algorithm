#include<bits/stdc++.h>
using namespace std;

int color[100];
int vis[100];

bool dfs(vector<int> g[],int node,int col)
{
    vis[node]=1;
    color[node]=col;

    for(auto it:g[node]){
        if(color[it]==0){
            if(color[node]==1){
                return dfs(g,it,2);
            }
            else
                return dfs(g,it,1);
        }
        else if(color[it]==color[node])
            return false;
    }
    return true;
}

bool detect(vector<int> g[],int n)
{
    for(int i=1; i<=n; i++){
        if(!vis[i])
        if(dfs(g,i,1)==false) return false;
    }
    return true;
}

int main()
{
    int v,e;
    cin>>v>>e;
    vector<int> g[v+1];

    for(int i=0; i<e; i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    if(detect(g,v))
        cout<<"bipartite"<<endl;
    else
        cout<<"Not bipartite"<<endl;
}
