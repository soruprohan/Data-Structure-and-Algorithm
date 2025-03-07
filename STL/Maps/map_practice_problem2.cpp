//https://www.hackerrank.com/challenges/cpp-maps/problem
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin>>q;
    map<string,int> m;
    while(q--){
        int type;
        cin>>type;
        string s;
        int x;

        if(type==1){
            cin>>s>>x;
            m[s]+=x;
        }
        else if(type==2){
            cin>>s;
            m.erase(s);
        }
        else{
            cin>>s;
            cout<<m[s]<<endl;
        }
    }
}
