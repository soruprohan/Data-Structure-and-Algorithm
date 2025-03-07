#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v;

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<"enter element:";
    int x;
    cin>>x;
    auto it=find(v.begin(),v.end(),x);

    if(it!=v.end())
        cout<<*it<<" is in the vector."<<endl;
    else
        cout<<"Element not found"<<endl;
}
