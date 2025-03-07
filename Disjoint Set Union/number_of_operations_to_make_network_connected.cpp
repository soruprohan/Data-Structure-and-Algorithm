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

int numOfoperations(int V,vector<pair<int,int>> &edges) //this is not adjacent list,watch int main()
{
    disjointSet ds(V);
    int ctextra=0;

    for(auto it: edges){

        int u=it.first;
        int v=it.second;

        if(ds.findparent(u)==ds.findparent(v))
            ctextra++;

        ds.unionbyRank(u,v);   //parent same hoileo unionbyRank function er vitore auto bad porbe same ultimate parent howa node gula,
                                    //tai else condition er dorkar nai,dileo somossa nai
    }

    int ct=0;
    for(int i=1; i<=V; i++){
        if(ds.findparent(i)==i)
            ct++;
    }

    int ans=ct-1; //jotpgula province thakebe tar theke ek kom edge lagbe all province ke connect korar jonno

    if(ctextra>=ans)
        return ans;
    else
        return -1;

}

int main()
{
    int V,E;
    cin>>V>>E;

    //this is not a adjacency list,this is edges in a pair,which is required in the context of this problem

    vector<pair<int,int>> edges;
    for(int i=0; i<E; i++){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    cout<<numOfoperations(V,edges)<<endl;
}
