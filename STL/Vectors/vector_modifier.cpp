#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &v)
{
    for(auto &value: v){
        cout<<value<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int> v(5),temp(5,18);

    for(auto it=v.begin(); it!=v.end(); it++){
        cin>>*it;
    }
    v.resize(3);
    print(v);

    v.resize(6,100);
    print(v);

    if(!v.empty()){
        cout<<v.front()<<endl;
        cout<<v.back()<<endl;
    }
    v.insert(v.begin()+2,69);
    print(v);
     v.insert(v.begin()+2,4,10);
    print(v);
    v.insert(v.begin()+2,temp.begin()+2,temp.end());
    print(v);
    v.erase(v.begin()+3);
    print(v);
    v.erase(v.begin()+2,v.begin()+7);
    print(v);
}
