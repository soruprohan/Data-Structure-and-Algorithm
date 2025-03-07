#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> size(n);
    vector<int> greed(m);

    for(int i=0; i<n; i++)
        cin>>size[i];
    for(int i=0; i<m; i++)
        cin>>greed[i];

    sort(size.begin(),size.end());
    sort(greed.begin(),greed.end());

    int l=0,r=0;
    while(l<n && r<m){
        if(size[l]>=greed[r]){
            r++;
        }
        l++;
    }
    cout<<r<<endl;
}
