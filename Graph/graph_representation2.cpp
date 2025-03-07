#include<bits/stdc++.h>

using namespace std;

const int N=100;
//int g1[N][N];

vector<int> g2[N];

int main()
{
    int v,e;
    cin>>v>>e;

    for(int i=0; i<e; i++){
        int v1,v2;
        cin>>v1>>v2;

        g2[v1].push_back(v2);
        g2[v2].push_back(v1);
    }
     for(int i=0; i<v; i++){
            for(int j=0; j<g2[i].size(); j++){
                cout<<g2[i][j]<<" ";
            }
            cout<<"\n";
        }
}

