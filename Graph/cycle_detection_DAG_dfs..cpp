#include<iostream>
#include<vector>
using namespace std;

int vis[100];
int pathvis[100];

bool dfs(vector<int> g[],int node)
{
    vis[node]=1;
    pathvis[node]=1;

    for(auto it: g[node]){
        if(!vis[it]){
            return dfs(g,it);
        }
        else if(pathvis[it]==1){
            return true;
        }
    }
    pathvis[node]=0;
    return false;
}

bool detect(vector<int> g[],int n)
{
    for(int i=0; i<n; i++){
        if(!vis[i])
            if(dfs(g,i)==true) return true;
    }
    return false;
}

int main()
{
        int n,m;
        cin>>n>>m;
        vector<int> g[n];
        for(int i=0; i<m; i++){
                int x,y;
                cin>>x>>y;
                g[x].push_back(y);
        }
           if(!detect(g,n)){
            cout<<"No cycle"<<endl;
        }
        else
            cout<<"cycle exists"<<endl;
}
