#include<bits/stdc++.h>
using namespace std;

const int M=1e9;

void bfs(vector<int> g[],int start,int *dis)
{
    queue<int> q;
    q.push(start);
    dis[start]=0;

    while(!q.empty()){
        int node=q.front();
        q.pop();

        for(auto it: g[node]){
            if(dis[node]+1 < dis[it]){
                dis[it]=dis[node]+1;
                q.push(it);
            }
        }
    }
}

int main()
{
     int n,m;
    cin>>n>>m;
    vector<int> g[n+1];

    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int dis[n+1];
    for(int i=1; i<=m; i++){
        dis[i]=M;
    }
    int start;
    cin>>start;
    bfs(g,start,dis);

    for(int i=1; i<=m; i++){
        cout<<dis[i]<<" ";
    }

}

