#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    cout<<"output using only auto keyword:"<<endl;
    for(auto it=v.begin(); it!=v.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<"output using auto keyword and ranged based loops combined:"<<endl;
    for(auto value: v){
        cout<<value.first<<" "<<value.second<<endl;
    }
}


