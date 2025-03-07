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

    auto func=[](int a){return a>0;};

    int check=any_of(v.begin(),v.end(),func);
    bool chec=any_of(v.begin(),v.end(),func);

    cout<<check<<endl;
    cout<<chec<<endl;
}

