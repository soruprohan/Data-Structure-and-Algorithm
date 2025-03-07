#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int v,e;
    cin>>v>>e;

    vector<pair<int,int>>g[v+1];

    for(int i=1; i<=e; i++){
        int x,y,wt;
        cin>>x>>y>>wt;

        g[x].push_back({y,wt});
        g[y].push_back({x,wt});
    }

    for(int i=1; i<=v; i++){
            cout<<i<<"- ";
        for(int j=0; j<g[i].size(); j++){
            cout<<"{"<<g[i][j].first<<","<<g[i][j].second<<"}";
        }
        cout<<endl;
    }
}
