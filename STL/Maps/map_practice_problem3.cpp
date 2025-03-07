//https://codeforces.com/problemset/problem/4/C
#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<string,int> m;
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        m[s]++;
        if(m[s]==1){
            cout<<"OK"<<endl;
        }
        else{
            cout<<s<<m[s]-1<<endl;
        }
    }
}
