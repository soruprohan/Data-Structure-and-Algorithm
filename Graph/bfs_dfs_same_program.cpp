#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(vector<int> g[],int start,int v,vector<int>& BFS)
{
    int vis[v]={0};
    queue<int> q;

    vis[start]=1;
    q.push(start);

    while(!q.empty()){
        int node=q.front();
        q.pop();
        BFS.push_back(node);

        for(auto it: g[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
}

void dfs(vector<int>g[],int node,int vis[],vector<int> &DFS)
{
    vis[node]=1;
    DFS.push_back(node);

    for(auto it:g[node]){
        if(!vis[it]){
            dfs(g,it,vis,DFS);
        }
    }
}

int main()
{
    int v,e;
    cin>>v>>e;

    vector<int>g[v+1];

    for(int i=0; i<e; i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int>DFS,BFS;

    int start;
    cout<<"Enter starting node:";
    cin>>start;

    bfs(g,start,v,BFS);

    for(auto it:BFS){
        cout<<it<<" ";
    }
    cout<<endl;

    int vis[v+1]={0};

    dfs(g,start,vis,DFS);

    for(auto it: DFS){
        cout<<it<<" ";
    }
    cout<<endl;
}
