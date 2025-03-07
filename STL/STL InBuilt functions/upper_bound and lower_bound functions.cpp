#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    //the array/vector must be sorted because upper_bound and lower_bound uses binary search techniques,so will fail the process if not sorted
     //will not work without this
    sort(v.begin(),v.end());

    int x;
    cin>>x;
    auto it=upper_bound(v.begin()+3,v.end(),x);
    auto it2=upper_bound(v.begin(),v.begin()+3,x);
    auto it3=lower_bound(v.begin(),v.end(),x);


    if(it==v.end())
        cout<<"element out of bound"<<endl;
    else
        cout<<*it<<endl;

    //ekhane upper bound exist na korle v.end() ashbe na 2nd case e,karon last element er next iterator v.begin()+3,not v.end()
    if(it2==v.begin()+3)
        cout<<"element out of bound"<<endl;
    else
        cout<<*it2<<endl;

    if(it3==v.end())
        cout<<"element out of bound"<<endl;
    else
        cout<<*it3<<endl;


}
