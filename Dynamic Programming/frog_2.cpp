#include<bits/stdc++.h>
using namespace std;

int frog(int n,vector<int>&a,vector<int> &dp,int k)
{
    if(n==0) return 0;

    if(dp[n]!=-1) return dp[n];

    int cost=INT_MAX;
    for(int i=1; i<=k; i++){
        if(n-i>=0)
            cost=min(cost,frog(n-i,a,dp,k)+abs(a[n]-a[n-i]));
    }
    
    return dp[n]=cost; 
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    vector<int> dp(n+1,-1);

    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<"min height = "<<frog(n-1,arr,dp,k);
}
