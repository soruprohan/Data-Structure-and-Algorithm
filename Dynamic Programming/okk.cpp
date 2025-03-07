#include<bits/stdc++.h>
using namespace std;

int func(int len,vector<int> &arr,vector<int>&dp)
{
    if(len==0) return 0;

    int ans= -1e9;
    for(int len_to_cut=1; len_to_cut<=len; len_to_cut++){
        if(len-len_to_cut>=0){
            ans=max(ans,func(len-len_to_cut,arr,dp)+arr[len_to_cut-1]);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int>dp(1010,-1);
    
    cout<<func(n,arr,dp);
}