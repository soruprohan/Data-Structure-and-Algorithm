#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<pair<string,string>,vector<int>> m;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string fn,ln;
        int q;
        cin>>fn>>ln>>q;

        for(int i=0; i<q; i++){
            int x;
            cin>>x;
            m[{fn,ln}].push_back(x);
        }
    }

    for(auto it:m){
        cout<<it.first.first<<" "<<it.first.second<<endl;
        cout<<it.second.size()<<endl;
        for(int it2 : it.second){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
}
