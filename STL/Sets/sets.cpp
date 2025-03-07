//Given N strings print the strings in lexicographical order.
//N<=10^5
//|s|<=10^5

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;

    set<string> s;

    for(int i=0; i<N; i++){
        string x;
        cin>>x;
        s.insert(x);
    }
    cout<<"Output:"<<endl;
    for(auto value: s){
        cout<<value<<endl;
    }
}
