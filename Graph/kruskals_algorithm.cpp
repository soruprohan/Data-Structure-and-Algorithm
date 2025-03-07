#include<bits/stdc++.h>
using namespace std;

class disjointSet
{
public:
    int rank[1000],size[1000],parent[1000];

    disjointSet(int n)
    {
        for(int i=0; i<=n; i++){
            rank[i]=0;
            size[i]=1;
            parent[i]=i;
        }
    }

    int findparent(int node)
    {
        if(parent[node]==node)
            return node;

        return parent[node]=findparent(parent[node]);
    }

    void unionByrank(int u,int v)
    {
        int ulp_u=findparent(u);
        int ulp_v=findparent(v);

        if(ulp_u==ulp_v)
            return;
        else if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBysize(int u,int v)
    {
        int ulp_u=findparent(u);
        int ulp_v=findparent(v);

        if(ulp_u==ulp_v)
            return;
        else if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }


};

int kruskal(vector<pair<int,int>> adj[],int v)
{
    int mstWt=0;

    vector<vector<int>> edges;

    for(int i=0; i<v; i++){ //suppose the problem was given as a 0 based graph
        for(auto it:adj[i]){
            int u=i;
            int v=it.first;
            int w=it.second;

            edges.push_back({w,u,v}); //store as {wt,u,v}
        }
    }

    sort(edges.begin(),edges.end());

    disjointSet ds(v);

    for(auto it:edges){
        int w=it[0];
        int u=it[1];
        int v=it[2];

        if(ds.findparent(u)!=ds.findparent(v)){
            ds.unionBysize(u,v);
            mstWt+=w;
        }
    }

    return mstWt;
}

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

    cout<<kruskal(adj,v)<<endl;
}
