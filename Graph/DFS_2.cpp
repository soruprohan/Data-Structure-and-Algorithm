#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dfs(vector<int>g[],int node,int vis[],vector<int> &DFS)
{
    vis[node]=1;
    DFS.push_back(node);

    for(auto it: g[node]){
        if(!vis[it]){
            dfs(g,it,vis,DFS);
        }
    }
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

    int start;
    cout<<"Enter starting node:";
    cin>>start;

    int vis[v+1]={0};
    vector<int>DFS;

    dfs(g,start,vis,DFS);

    for(auto it:DFS){
        cout<<it<< " ";
    }

}

