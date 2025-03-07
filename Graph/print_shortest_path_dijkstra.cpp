#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int v,vector<vector<int>> adj[],int source,int des)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dis(v+1,1e9),parent(v+1);
    for(int i=1; i<=v; i++) parent[i]=i;

    dis[1]=0;
    pq.push({0,1});

    while(!pq.empty()){
        int node=pq.top().second;
        int dist=pq.top().first;
        pq.pop();

        for(auto it: adj[node]){
            int adjnode=it[0];
            int edwt=it[1];

            if(dis[adjnode]> dist+edwt){
                dis[adjnode]=dist+edwt;
                pq.push({dis[adjnode],adjnode});

                parent[adjnode]=node;
            }
        }
    }

    if(dis[v]==1e9) return {-1};
    vector<int> path;

    int node=v;
    while(node!=parent[node]){
        path.push_back(node);
        node=parent[node];
    }

    path.push_back(node); //karon last node add hoy na,loop theke ber hoye ashe,tai manually add korte hoy
    reverse(path.begin(),path.end());
    return path;

}

int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<int>> adj[v+1];

    for(int i=0; i<e; i++){
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }

    vector<int> ans=dijkstra(v,adj,1,v); //assume 1 base indexing and question onujayi 1 theke suru hoy and last node ta destination hoy,but this can be done for any source or desetination

    for(auto it : ans){
        cout<<it<<" ";
    }
}

