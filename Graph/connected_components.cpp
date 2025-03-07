#include<bits/stdc++.h>
using namespace std;

bool vis[100];

void print_cc(vector<vector<int>> v)
{
    for(auto it:v){
        for(auto it2: it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void dfs(vector<int>g[],int node,vector<int>&DFS)
{
    if(vis[node])
        return ;
    vis[node]=true;
    DFS.push_back(node);

    for(auto it: g[node]){
        dfs(g,it,DFS);
    }
    return;
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

    vector<int>DFS;
    vector<vector<int>> cc;
    for(int i=1; i<=n; i++){

        if(!vis[i]){
            DFS.clear();
            dfs(g,i,DFS);
            cc.push_back(DFS);
        }
    }
    cout<<"Number of connected components:"<<cc.size()<<endl;
    cout<<"The nodes in connected components are:"<<endl;
    print_cc(cc);

}
