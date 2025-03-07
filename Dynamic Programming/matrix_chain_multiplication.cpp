#include<bits/stdc++.h>
using namespace std;

int func(int i,int j,int *arr,vector<vector<int>> &dp)
{
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int ans=INT_MAX;
    for(int k=i; k<j; k++){
        int steps=arr[i-1]*arr[k]*arr[j]+func(i,k,arr,dp)+func(k+1,j,arr,dp);
        ans=min(ans,steps);
    }
    return dp[i][j]=ans;
}

int main()
{
    int n=5;
    vector<vector<int>> dp(n,vector<int>(n,-1));
    int arr[]={10,20,30,40,50};
    cout<<func(1,n-1,arr,dp);
}
