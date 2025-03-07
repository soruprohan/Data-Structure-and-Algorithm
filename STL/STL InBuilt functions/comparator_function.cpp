#include<bits/stdc++.h>

using namespace std;


bool check(pair<int,int> a,pair<int,int> b) //This function is called comparator function
{
    if(a>b)
        return true;
    else
        return false;
}
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i].first>>v[i].second;
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(check(v[i],v[j]))
                swap(v[i],v[j]);
        }
    }

    cout<<"After sorting:"<<endl;
    for(int i=0; i<n; i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
}
