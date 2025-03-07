#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v,v2;

    int n;
    cout<<"Enter size:";
    cin>>n;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    int x;
    cout<<"Enter value:";
    cin>>x;

    int ct=count(v.begin(),v.end(),x);
    cout<<ct<<endl;

    auto it=v.begin();

    for(int i=0; i<n; i++){
        if(find(it,v.end(),x)!=v.end()){

            it=find(it,v.end(),x);
            int index=it-v.begin();
            v2.push_back(index);
            advance(it,1); //or it=it+1
        }
    }

    cout<<v2.size()<<endl;

    cout<<"The value found at indices:"<<endl;
    for(int i=0; i<v2.size(); i++){
        cout<<v2[i]<<" ";
    }
    cout<<endl;
}
