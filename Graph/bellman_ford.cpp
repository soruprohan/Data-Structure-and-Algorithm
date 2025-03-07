#include<bits/stdc++.h>
using namespace std;

vector<int> bellman(int v,vector<vector<int>> &edges,int src)
{
    vector<int> dis(v,1e9); //to handle also 1 based graph use v+1
    dis[src]=0;

    for(int i=1; i<=(v-1); i++){
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            if(dis[u]!=1e9 && dis[v]>dis[u]+wt){
                dis[v]=dis[u]+wt;
            }
        }
    }

    //nth relaxation to check the negative cycle
    for(auto it:edges){
        int u=it[0];
        int v=it[1];
        int wt=it[2];

        if(dis[u]!=1e9 && dis[v]>dis[u]+wt){
            return {-1};
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