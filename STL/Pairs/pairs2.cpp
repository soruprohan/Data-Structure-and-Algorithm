#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout<<"Enter number of students:"<<endl;
    cin>>n;
    pair<int,string> p[n];

    cout<<"Enter roll and name :"<<endl;
    for(int i=0; i<n; i++){
       cin>>p[i].first>>p[i].second;
    }
    for(int i=0;i<n; i++){
        cout<<p[i].first<<" "<<p[i].second<<endl;

    }
}
