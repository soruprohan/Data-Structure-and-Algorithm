#include<bits/stdc++.h>
using namespace std;

int wt[105],val[105];
int dp[105][100005];

long long func(int ind,int value_left){
   
   if(value_left==0) return 0;
   if(ind<0) return INT_MAX;
   if(dp[ind][value_left]!=-1) return dp[ind][value_left];

   long long ans=INT_MAX;

   if(value_left-val[ind]>=0)
     ans=min(ans,func(ind-1,value_left-val[ind])+wt[ind]+0LL);

    ans=min(ans,func(ind-1,value_left));

     return dp[ind][value_left]=ans;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int n,w;
    cin>>n>>w;

    for(int i=0; i<n; i++){
        cin>>wt[i]>>val[i];
    }

    int maxvalue=1e5;

    for(int i=maxvalue; i>=0; i--){
        if(func(n-1,i)<=w){
            cout<<i<<endl;
            break;
        }
    }
}