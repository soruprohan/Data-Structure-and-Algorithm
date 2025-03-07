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

    vector<pair<int,int>> :: iterator it;

    cout<<"output using iterators:"<<endl;
    for(it=v.begin(); it!=v.end();it++){
        cout<<(*it).first<<" "<<it->second<<endl;
    }

    cout<<"output using ranged based loops:"<<endl;
    for(pair<int,int> value : v){
        cout<<value.first<<" "<<value.second<<endl;
    }
    cout<<"output using reference of ranged based loops,meaning directy changing the actual vector:"<<endl;
    for(pair<int,int> &value:v){
        cout<<value.first<<" "<<value.second<<endl;
        value.first++;
        value.second++;
    }
     cout<<"output using ranged based loops now that the values are changed:"<<endl;
    for(pair<int,int> value : v){
        cout<<value.first<<" "<<value.second<<endl;
    }
}

