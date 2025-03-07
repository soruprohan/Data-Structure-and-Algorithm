#include<iostream>
#include<vector>
using namespace std;
//here the list is 1 based,means it starts from 1
int main()
{
  int v,e;
  cin>>v>>e;

  vector<int> g[v+1];

  for(int i=1; i<=e; i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
  }

  for(int i=1; i<=v; i++){
    cout<<i<<"-";
    for(int j=0; j<g[i].size(); j++){
        cout<<g[i][j]<<" ";
    }
    cout<<endl;
  }
}
