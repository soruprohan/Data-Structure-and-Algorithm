#include<bits/stdc++.h>
using namespace std;

int indegree[100];

void print(vector<int> &v)
{
    if(v.size()==0){
        cout<<"Course not possible"<<endl;
        return;
    }
    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
}

vector<int> find_order(vector<int>g[],int n)
{
    queue<int> q;
    vector<int> ans;

    for(int i=0; i<n; i++){
        for(auto it:g[i]){
            indegree[it]++;
        }
    }

    for(int i=0; i<n; i++){
        if(indegree[i]==0){
            q.push(i);
        }
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
    if(ans.size()==n)
        return ans;
    else
    return {};
}

int main()
{
    int v,e;
    cin>>v>>e;
    pair<int,int> p;       //hudai
    vector<int> g[v];
    for(int i=0; i<v; i++){
        int x,y;
        cin>>x>>y;
        p={x,y};
        g[p.first].push_back(p.second);
    }

    vector<int> ans=find_order(g,v);
    print(ans);
}
