#include<bits/stdc++.h>
using namespace std;
void print(map<int,string> m)
{
    cout<<"output using iterator:"<<endl;

    map<int,string> :: iterator it;
    for(it=m.begin(); it!=m.end(); it++)
    {
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }

    cout<<"output using ranged based loops"<<endl;
    for(auto value: m){
        cout<<value.first<<" "<<value.second<<endl;
    }
}
int main()
{
    map<int,string> m;
    m[1]="abc";
    m[2]="ok";
    m[3]="acd";
    m[3]="cse";
    m[3]="mse shera"; //same key different value.sobar last e insert kora value ta nibe.Unordered map eo same

    m.insert({4,"afg"});
    m.insert({6,"ok"});
    m[5]="cse";
    print(m);
}
