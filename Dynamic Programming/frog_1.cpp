#include<bits/stdc++.h>
using namespace std;

int frog(int n,vector<int>&a,vector<int> &dp)
{
    if(n==0) return 0;
    if(n==1) return abs(a[1]-a[0]);

    if(dp[n]!=-1) return dp[n];

    int left=frog(n-1,a,dp)+abs(a[n]-a[n-1]);
    int right=frog(n-2,a,dp)+abs(a[n]-a[n-2]);

    return dp[n]=min(left,right); 
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> dp(n+1,-1);

    for(int i=0; i<n; i++)
        cin>>a[i];

    cout<<"min height = "<<frog(n-1,a,dp)<<endl;

    //iterative or bottom up approach
    dp.resize(n,-1);
    dp[0]=0;
    dp[1]=abs(a[1]-a[0]);
    for(int i=2; i<n; i++){
        int left=dp[i-1]+abs(dp[i]-dp[i-1]);
        int right=dp[i-2]+abs(dp[i]-dp[i-2]);
        dp[i]=min(left,right);
    }
    cout<<"bottom up="<<dp[n-1]<<endl;
}
