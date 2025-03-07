#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int v[n];

    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    //the array/vector must be sorted because upper_bound and lower_bound uses binary search techniques,so will fail the process if not sorted
     //will not work without this

    sort(v,v+n);

    int x;
    cin>>x;
    auto ptr=upper_bound(v,v+n,x);
    auto ptr2=lower_bound(v,v+n,x);

    if(ptr==(v+n))
        cout<<"element out of bound"<<endl;
    else
        cout<<*ptr<<endl;

    if(ptr2==(v+n))
        cout<<"element out of bound"<<endl;
    else
        cout<<*ptr2<<endl;
}
