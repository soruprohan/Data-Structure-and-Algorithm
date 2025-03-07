#include<bits/stdc++.h>
using namespace std;

int lis(int n,vector<int>&a,vector<int> &dp)
{
    if(dp[n]!=-1) return dp[n];

    int ans=1;
    for(int i=0; i<n; i++){
        if(a[i]<a[n]){ 
            ans=max(ans,lis(i,a,dp)+1);  
        }             
    }
    return dp[n]=ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> dp(n,-1);
    for(int i=0; i<n; i++)
        cin>>a[i];   

    int ans=INT_MIN; //or you can keep 0 since atleast the ans will be 1
    for(int i=0; i<n; i++){
        ans=max(ans,lis(i,a,dp));
    }
    cout<<ans<<endl;
}