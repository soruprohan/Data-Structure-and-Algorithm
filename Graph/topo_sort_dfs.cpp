#include<bits/stdc++.h>
using namespace std;

int vis[100];

void print(vector<int> &v)
{
    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
}
void dfs(vector<int> g[],int node,stack<int> &st)
{
        vis[node]=1;
        for(auto it:g[node]){
            if(!vis[it])
                dfs(g,it,st);
        }
        st.push(node);
}

vector<int> toposort(vector<int> g[],int n)
{
        stack<int> st;
        vector<int> ans;
        for(int i=0; i<n; i++){
                if(!vis[i])
                    dfs(g,i,st);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
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

        vector<int> ans=toposort(g,n);
        print(ans);
}
