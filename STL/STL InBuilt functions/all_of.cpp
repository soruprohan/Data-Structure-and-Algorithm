#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout<<"Element number:";
    cin>>n;

    vector<int> v;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    int check=all_of(v.begin(),v.end(),[](int a){return a>0;});
    bool chec=all_of(v.begin(),v.end(),[](int a){return a>0;});

    cout<<check<<endl;
    cout<<chec<<endl;
}
