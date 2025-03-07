#include<bits/stdc++.h>
using namespace std;

class disjointSet
{
public:
    int parent[100],rank[100],size[100];
    disjointSet(int n)
    {
        for(int i=0; i<=n; i++){
            parent[i]=i;
            rank[i]=0;
            size[i]=1;
        }
    }

    int findparent(int node)
    {
        if(parent[node]==node)
            return node;
        else
            return parent[node]=findparent(parent[node]);
    }

    void unionbyRank(int u,int v)
    {
        int ulp_u=findparent(u);
        int ulp_v=findparent(v);
        if(ulp_u==ulp_v)
            return;
        else if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionbySize(int u,int v)
    {
        int ulp_u=findparent(u);
        int ulp_v=findparent(v);
        if(ulp_u==ulp_v)
            return;
        else if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution
{
public:
    int spanningTree(int v,vector<pair<int,int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        for(int i=1; i<=v; i++){        //in this case the problem statement was 1 based
            for(auto it:adj[i]){
                int node=i;
                int adjnode=it.first;
                int wt=it.second;
                edges.push_back({wt,{node,adjnode}});
            }
        }

        sort(edges.begin(),edges.end());

        disjointSet ds(v);
        int mstWt=0;

        for(auto it:edges){
            int u=it.second.first;
            int v=it.second.second;
            int wt=it.first;
            if(ds.findparent(u)!=ds.findparent(v)){
                ds.unionbySize(u,v);
                mstWt+=wt;
            }
        }
         return mstWt;
    }

};
int main()
{
    int v,e;
    cin>>v>>e;
    vector<pair<int,int>> adj[v+1];

    for(int i=0; i<e; i++){
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    Solution obj;
    cout<<obj.spanningTree(v,adj)<<endl;
}
