#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> v;

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        string x;
        cin>>x;
        v.push_back(x);
    }
    string s;
    cout<<"Enter string you want to find:";
    cin>>s;
    auto it=find(v.begin(),v.end(),s);

    if(it!=v.end())
        cout<<*it<<" is in the vector."<<endl;
    else
        cout<<"Element not found"<<endl;
}
