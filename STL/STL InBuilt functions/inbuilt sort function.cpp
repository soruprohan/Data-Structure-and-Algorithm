#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    //This part is for array
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    vector<int> v;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
           v.push_back(x);
    }

    sort(v.begin(),v.end());

    vector<int> ::iterator it;
    for(it=v.begin(); it!=v.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    sort(a,a+n);

    for(int i : a){
        cout<<i<<" ";
    }
}
