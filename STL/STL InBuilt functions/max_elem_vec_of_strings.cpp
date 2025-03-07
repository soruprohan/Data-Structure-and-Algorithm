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
   auto it=max_element(v.begin(),v.end());

    cout<<*it<<endl;
    cout<<max({1,2,3,4});
}
