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

int main()
{
    disjointSet ds(7);
    ds.unionbyRank(1,2);
    ds.unionbyRank(2,3);
    ds.unionbyRank(4,5);
    ds.unionbyRank(6,7);
    ds.unionbyRank(5,6);

    if(ds.findparent(3)==ds.findparent(7))
        cout<<"same"<<endl;
    else
        cout<<"not same"<<endl;

    ds.unionbyRank(3,7);
    if(ds.findparent(3)==ds.findparent(7))
        cout<<"same"<<endl;
    else
        cout<<"not same"<<endl;

    disjointSet ds2(7);
    ds2.unionbySize(1,2);
    ds2.unionbySize(2,3);
    ds2.unionbySize(4,5);
    ds2.unionbySize(6,7);
    ds2.unionbySize(5,6);

    if(ds2.findparent(3)==ds2.findparent(7))
        cout<<"same"<<endl;
    else
        cout<<"not same"<<endl;

    ds2.unionbySize(3,7);
    if(ds2.findparent(3)==ds2.findparent(7))
        cout<<"same"<<endl;
    else
        cout<<"not same"<<endl;
}
