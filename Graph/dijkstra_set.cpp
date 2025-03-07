#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int v,vector<vector<int>> adj[],int s)
{
    set<vector<int>> st;
    vector<int> dis(v,1e9);
    dis[s]=0;

    st.insert({0,s});

    while(!st.empty()){
        auto it= *(st.begin());
        int distance=it[0];
        int node=it[1];
        st.erase(it);

        for(auto it2: adj[node]){
            int edwt=it2[1];
            int adjNode=it2[0];

            if(distance+edwt < dis[adjNode]){
                if(dis[adjNode] !=1e9)
                    st.erase({dis[adjNode],adjNode});

                dis[adjNode]=distance+edwt;
                st.insert({dis[adjNode],adjNode});
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

