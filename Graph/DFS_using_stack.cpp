#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//this method may not give the traditional dfs recursion output in squence,but it's dfs alright
void dfs(vector<int>g[],int start,int vis[],vector<int> &DFS)
{
    stack<int>st;
    vis[start]=1;
    st.push(start);

    while(!st.empty()){
        int node=st.top();
        st.pop();
        DFS.push_back(node);

        for(int it: g[node]){
            if(!vis[it]){
                vis[it]=1;
                st.push(it);
            }
        }
    }
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

    int vis[v+1]={0};
    vector<int>DFS;

    dfs(g,start,vis,DFS);

    for(auto it:DFS){
        cout<<it<< " ";
    }

}


