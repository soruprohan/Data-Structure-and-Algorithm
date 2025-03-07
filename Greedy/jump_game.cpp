#include<bits/stdc++.h>
using namespace std;

bool jump(vector<int> &v,int n)
{
    int maxInd=0;
    for(int i=0; i<n; i++){
        if(i>maxInd) return false;
        maxInd=max(maxInd,i+v[i]);
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    cout<<jump(v,n);
}
