//https://www.hackerrank.com/challenges/cpp-sets/problem?fbclid=IwAR1Z1fv5RnGAqByvADCRUv4pYQAAmQ_zV5rgVVCagY-DneWu6TSWENdncsY
#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    int q;
    cin>>q;
    while(q--){
        int y,x;
        cin>>y>>x;
        if(y==1){
            s.insert(x);
        }
        else if(y==2){
            auto it=s.find(x);
            if(it!=s.end())
                s.erase(it);
        }
        else{
            auto it=s.find(x);
            if(it!=s.end())
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
}

