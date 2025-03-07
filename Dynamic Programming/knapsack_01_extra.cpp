#include<bits/stdc++.h>
using namespace std;

int wt[105],val[105];
long long dp[105][100005];

//knapsack 1 problem of atcoder but my approach not luv's
long long func(int ind,int wt_left,int n){
    if(wt_left== 0) return 0;
    if(ind>=n) return 0;
    if(dp[ind][wt_left] !=-1) return dp[ind][wt_left];

    long long ans=INT_MIN;
    //take
    if(wt_left-wt[ind]>=0)
         ans=func(ind+1,wt_left-wt[ind],n) +val[ind];
    //not take
        ans=max(ans,func(ind+1,wt_left,n));

    return dp[ind][wt_left]=ans;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int n,w;
    cin>>n>>w;

    for(int i=0; i<n; i++){
        cin>>wt[i]>>val[i];
    }

    cout<<func(0,w,n);
}