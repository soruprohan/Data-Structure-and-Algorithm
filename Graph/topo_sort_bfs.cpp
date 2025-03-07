#include<bits/stdc++.h>
using namespace std;

int indegree[100];

void print(vector<int> &v)
{
    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
}

vector<int> toposort(vector<int> g[],int n)
{
        queue<int> q;
        vector<int> ans;

        for(int i=0; i<n; i++){
            for(auto it:g[i]){
                indegree[it]++;
            }
        }

        for(int i=0; i<n; i++){
            if(indegree[i]==0)
                q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for(auto it:g[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
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

