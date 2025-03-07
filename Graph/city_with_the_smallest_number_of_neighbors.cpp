#include<bits/stdc++.h>
using namespace std;

int findCity(vector<vector<int>> &dis,int threshold)
{
    int v=dis.size();

    for(int i=0; i<v; i++)
        dis[i][i]=0;

    for(int k=0; k<v; k++){
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(dis[i][k]== 1e9 || dis[k][j]==1e9)
                    continue;
                if(dis[i][j] > dis[i][k]+dis[k][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
            }
        }
    }
    int cntCity=v;
    int cityNo=-1;

    for(int city=0; city<v; city++){
        int cnt=0;
        for(int adjCity=0; adjCity<v; adjCity++){
            if(dis[city][adjCity]<= threshold)
                cnt++;
        }
        if(cnt<=cntCity){
            cntCity=cnt;
            cityNo=city;
        }
    }
    return cityNo;

}

int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<int>> dis(v,vector<int>(v,1e9));

    for(int i=0; i<e; i++){
        int u,v,w;
        cin>>u>>v>>w;

        dis[u][v]=w;
        dis[v][u]=w;  //bidirectional stated in the question
    }
    int threshold;
    cin>>threshold;

    cout<<findCity(dis,threshold)<<endl;
}
