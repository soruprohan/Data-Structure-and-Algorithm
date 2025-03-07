#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<pair<int,int>>v[N];

    for(int i=0; i<N; i++){
        int n;
        cout<<"size:";
        cin>>n;
        for(int j=0; j<n; j++){
            int x,y;
            cin>>x;
            cin>>y;
            v[i].push_back({x,y});
        }
    }
    vector<pair<int,int>> :: iterator it;

    for(int i=0; i<N; i++){
        cout<<"size is: "<<v[i].size()<<endl;
        for(it=v[i].begin(); it!=v[i].end(); it++){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
    }

}
