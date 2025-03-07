#include<bits/stdc++.h>
using namespace std;

int dp[1005];
int func(int len,vector<int> &prices)
{
    if(len==0) return 0;
    int ans=INT_MIN;
    if(dp[len]!=-1) return dp[len];

    for(int len_to_cut=1; len_to_cut<=len; len_to_cut++){
        if(len-len_to_cut >=0){
            ans=max(ans,func(len-len_to_cut,prices) +prices[len_to_cut-1]); //0 based indexing
        }
    }
    return dp[len]=ans;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    
    int n;
    cin>>n;
    vector<int> prices(n);
    for(int i=0; i<n; i++){
        cin>>prices[i];
    }
    cout<<func(n,prices);
}
