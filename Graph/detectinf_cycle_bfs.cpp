#include<bits/stdc++.h>
using namespace std;

int vis[100];

bool bfs(vector<int> g[],int start)
{
    queue<pair<int,int>> q;
    q.push({start,-1});
    vis[start]=1;

    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();

        for(auto it: g[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push({it,node});
            }
            else if(parent!=it)
                return true;
        }
    }
    return false;
}

bool check(vector<int> g[],int n)
{
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(bfs(g,i)) return true;
        }
    }
    return false;
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

    cout<<check(g,n)<<endl;
}


