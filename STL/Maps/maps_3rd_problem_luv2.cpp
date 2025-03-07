#include<bits/stdc++.h>
using namespace std;
//eta original problem er ulta,ekhane lexicographically ulta store hobe
//ektu kothin vabe kora syntax gulo for concept
//auto keyword,rbegin() and rend() diye easily hoy

int main()
{
    map<int,multiset<string>> m;
    int n;
    cin>>n;
    string s;
    int x;

    for(int i=0; i<n; i++){
        cin>>s>>x;
        m[x].insert(s);
    }

    map<int,multiset<string>> ::iterator it=--m.end();
    while(true){
        multiset<string> :: iterator it2=--(*it).second.end();

        while(true){
            cout<<*it2<<" "<<it->first<<endl;
            if(it2==it->second.begin())
                break;
            it2--;
        }

        if(it==m.begin())
            break;
        it--;
    }

}
