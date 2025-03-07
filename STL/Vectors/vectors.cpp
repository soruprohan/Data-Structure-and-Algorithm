#include<bits/stdc++.h>

using namespace std;

void printvector(vector<int> v)
{
    cout<<"size: "<<v.size()<<endl;
    for(int i=0; i<v.size(); i++){
        cout<< v[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector< int> v;
    cout<<v.capacity()<<endl;
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        printvector(v);
        v.push_back(x);
    }
    printvector(v);
}
