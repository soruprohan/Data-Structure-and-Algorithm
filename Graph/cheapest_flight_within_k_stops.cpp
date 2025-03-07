#include<bits/stdc++.h>
using namespace std;

int mincost(int v,vector<vector<int>> adj[],int src,int dst,int k)
{
    queue<pair<int,pair<int,int>>> q;
    vector<int> dis(v,1e9); //this is cost array,the name is taken as dis
    dis[src]=0;
    q.push({0,{src,0}}); //stops , node,cost

    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int stops=it.first;
        int node=it.second.first;
        int cost=it.second.second;

        if(stops>k) continue; //no need to check the adjacent nodes of a node that has already exceeded the K,because its next adjacents will have stop+1

        for(auto it:adj[node]){
            int adjnode=it[0];
            int edwt=it[1];

            if(stops<=k && edwt+cost< dis[adjnode]){
                dis[adjnode]=cost+edwt;
                q.push({stops+1,{adjnode,dis[adjnode]}});
            }
        }
    }

    if(dis[dst] ==1e9) return -1;
    return dis[dst];

}

int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<int>> adj[v+1];

    for(int i=0; i<e; i++){
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w}); //directed graph
    }

    int src,dst,K;
    cin>>src>>dst>>K;
    int cost=mincost(v,adj,src,dst,K);
    cout<<cost<<endl;
}

