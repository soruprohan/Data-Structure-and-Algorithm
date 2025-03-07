#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &v)
{
    for(auto it:v){
        for(auto it2:it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
}

int spanning(vector<pair<int,int>> adj[],int n,vector<vector<int>> &MST)
{
    priority_queue<vector<int> ,vector<vector<int>>,greater<vector<int>> > pq;
    int sum=0;
    vector<int>vis(n,0);
    //we will be pushing ({wt,source,parent})
    pq.push({0,0,-1});
    vis[0]=1;

    while(!pq.empty())
    {
        auto it=pq.top();
        int wt=it[0];
        int node=it[1];
        int parent=it[2];
        pq.pop();

        if(!vis[node] && parent!=-1){
            vis[node]=1;
            MST.push_back({node,parent,wt});
            sum+=wt;
        }

        for(auto it:adj[node]){
            int adjNode=it.first;
            int wt=it.second;

            if(!vis[adjNode]){
                pq.push({wt,adjNode,node}); //{wt,node,parent}
            }
        }

    }

    return sum;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1];

    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<vector<int>> MST;
    int sum=spanning(adj,n,MST);

    cout<<endl;
    print(MST);

    cout<<"The total weight of the MST is:"<<sum<<endl;
}
