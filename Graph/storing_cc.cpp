#include<bits/stdc++.h>
using namespace std;

const int N=1000;

vector<int> g[N];
bool vis[N];

vector<int> current_cc;
vector<vector<int>> cc;

void dfs(int vertex)
{
    vis[vertex]=true;
    current_cc.push_back(vertex);

    for(int child : g[vertex]){
        if(vis[child]==true) continue;

        dfs(child);
    }
}

int main()
{
    int n,e;
    cin>>n>>e;

    for(int i=0; i<e; i++){
        int v1,v2;
        cin>>v1>>v2;

        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    for(int i=1; i<=n; i++){
        if(vis[i]==true)
            continue;

        current_cc.clear(); //this is must
        dfs(i);
        cc.push_back(current_cc);
    }

    cout<<"Total connected components :"<<cc.size()<<endl;
    for(auto vectors : cc){
            for(int i=0; i<vectors.size(); i++){
                cout<<vectors[i]<<" ";
            }
            cout<<endl;
    }
}
