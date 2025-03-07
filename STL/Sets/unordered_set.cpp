//Given N strings and Q queries.In each query you are given a string .
//Print yes if the string is present ,else print no.
//
//N<=10^6
//|S|<=100
//Q<=10^6

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;

    unordered_set<string> s;

    for(int i=0; i<N; i++){
        string x;
        cin>>x;
        s.insert(x);
    }
    cout<<"Give query:";
    int Q;
    cin>>Q;
    while(Q--){
        string x;
        cin>>x;
        if(s.find(x)!=s.end())
            cout<<"Yes";
        else
            cout<<"No";
    }

}
