#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int v,vector<vector<int>> adj[],int s)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q; //syntax for declaring min heap priority queue
    vector<int>dis(v,1e9); //v+1 can handle 1 based indexing
    dis[s]=0;
    q.push({0,s});

    while(!q.empty()){
        int distance=q.top().first; //priority queue te front hoy na,top hoy
        int node=q.top().second;
        q.pop();

        for(auto it:adj[node]){
            int adjNode=it[0];
            int edwt=it[1];

            if(distance+edwt < dis[adjNode]){
                dis[adjNode]=distance+edwt;
                q.push({dis[adjNode],adjNode});
            }
        }
    }
    return dis;

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
    int s;
    cout<<"Enter source node:";
    cin>>s;
    vector<int> ans=dijkstra(v,adj,s);

    for(auto it : ans){
        cout<<it<<" ";
    }
}
