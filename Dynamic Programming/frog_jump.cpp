#include<bits/stdc++.h>
using namespace std;

int frog(int n,vector<int>&a,vector<int> &dp)
{
    if(n==0)
        return 0;
    if(dp[n]!=-1) return dp[n];

    int left=frog(n-1,a,dp)+abs(a[n]-a[n-1]);
    int right=INT_MAX;
    if(n>1)
         right=frog(n-2,a,dp)+abs(a[n]-a[n-2]);

    return dp[n]=min(left,right);
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> dp(n+1,-1);

    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<"min height = "<<frog(n-1,arr,dp);
}
