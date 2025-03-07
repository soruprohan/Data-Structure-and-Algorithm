#include<bits/stdc++.h>
using namespace std;

vector<int> bellman(int V,vector<vector<int>> &edges,int src)
{
    vector<int> dis(V+1,1e9),parent(V+1);
    for(int i=0; i<=V; i++) parent[i]=i;  //this will work for both 0 based and 1 based graph
    dis[src]=0;

    for(int i=0; i<V-1; i++){
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            if(dis[u]!=1e9 && dis[u]+wt < dis[v]){
                dis[v]=dis[u]+wt;
                parent[v]=u;
            }
        }
    }

    int x;
    for(auto it:edges){
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        if(dis[u]!= 1e9 && dis[u]+wt <dis[v]){
            x=v;
        }
    }

    return dis;
}

int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<int>> edges; //its not adjacency list,rather a list of edges

    for(int i=0; i<e; i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        edges.push_back({x,y,wt});
    }

    int src;
    cin>>src;

    vector<int> dis=bellman(v,edges,src);
}

