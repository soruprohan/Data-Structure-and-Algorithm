#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> bfs(vector<int> g[],int start,int v)
    {
        int vis[v]={0};
        queue<int> q;
        vis[start]=1;
        q.push(start);

        vector<int> BFS;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            BFS.push_back(node);

            for(int i=0; i<g[node].size(); i++){
                if(!vis[g[node][i]]){
                    vis[g[node][i]]=1;
                    q.push(g[node][i]);
                }
            }
        }
        return BFS;
    }

int main()
{
    int v,e;
    cin>>v>>e;
    vector<int> g[v+1];

    for(int i=0; i<e; i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int start;
    cout<<"Enter starting node:";
    cin>>start;

    vector<int> BFS=bfs(g,start,v);
    for(auto it: BFS){
        cout<<it<<" ";
    }
}
