#include<bits/stdc++.h>
using namespace std;

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

    for(auto it=m.rbegin(); it!=m.rend(); it++){

        for(auto &it2 : (*it).second){
            cout<<it2<<" "<<(*it).first<<endl;
        }
    }
}
