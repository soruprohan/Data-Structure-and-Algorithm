#include<bits/stdc++.h>
using namespace std;


void print(vector<vector<int>> &g)
{
    for(auto it:g){
        for(auto it2:it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
}

void floydWarshal(vector<vector<int>> &dis)
{
    int v=dis.size();


    for(int i=0; i<v; i++){
        dis[i][i]=0;
    }

    for(int k=0; k<v; k++){
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(dis[i][k]== 1e9 || dis[k][j]==1e9)
                    continue;
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }

    //this portion is not on the original floyd warshal code,this is for checking negative cycle
    for(int i=0; i<v; i++){
        if(dis[i][i]<0){
            cout<<"negative cycle exists"<<endl;
            break;
        }
    }
}

int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<int>> dis(v,vector<int>(v,1e9)); //set v+1 for 1 based graph

    for(int i=0; i<e; i++){
        int u,v,w;
        cin>>u>>v>>w;
        dis[u][v]=w;
    }

    floydWarshal(dis);
    print(dis);
}

