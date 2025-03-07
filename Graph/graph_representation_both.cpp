#include<bits/stdc++.h>
using namespace std;

const int N=100;

int g1[N][N];
vector<pair<int,int>> g2[N];

int main()
{
    int v,e;
    cout<<"Enter total number of vertices end edges"<<endl;
    cin>>v>>e;
    cout<<"Serially enter vertex1,vertex2 and weight between them:"<<endl;
    for(int i=0; i<e; i++){
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        g1[v1][v2]=wt;
        g1[v2][v1]=wt;

        g2[v1].push_back({v2,wt});
        g2[v2].push_back({v1,wt});
    }

    cout<<"accessing adjacency matrix:"<<endl;
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            cout<<g1[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"accessing adjacency list:"<<endl;

    for(int i=0; i<v; i++){
        for(int j=0; j<g2[i].size(); j++){
            cout<<"("<<g2[i][j].first<<","<<g2[i][j].second<<") ";
        }
        cout<<endl;
    }
}
