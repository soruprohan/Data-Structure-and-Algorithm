#include<bits/stdc++.h>
using namespace std;

class disjointSet
{
    int rank[1000],parent[1000],size[1000];
public:
    disjointSet(int n)
    {
        for(int i=0; i<=n; i++){    //these functions work for both 0 based and 1 based graphs
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
        if(rank[ulp_u] < rank[ulp_v]){
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

    void unionbySize(int u,int v)
    {
        int ulp_u=findparent(u);
        int ulp_v=findparent(v);
        if(ulp_u==ulp_v)
            return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

int numOfprovinces(int v,vector<int> adj[])
{
    disjointSet ds(v);

    for(int i=1; i<=v; i++){
        for(auto it:adj[i]){
            ds.unionbyRank(i,it);
        }
    }
    int ct=0;
    for(int i=1; i<=v; i++){
        if(ds.findparent(i)==i)
            ct++;
    }
    return ct;
}

int main()
{
    int v,e;
    cin>>v>>e;

    vector<int> adj[v+1];
    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<numOfprovinces(v,adj)<<endl;
}

