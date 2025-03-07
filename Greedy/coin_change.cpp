#include<bits/stdc++.h>
using namespace std;

vector<int>func(vector<int> &v,int target)
{
    int n=v.size();
    vector<int> ans;
    for(int i=n-1; i>=0; i--){
        while(target>=v[i]){
            target-=v[i];
            ans.push_back(v[i]);
        }
    }
    return ans;
}

int main()
{
    vector<int> coins={1,2,5,10,20,50,100,500,1000};
    int target;
    cin>>target;
    vector<int> ans=func(coins,target);
    for(auto it:ans) cout<<it<<" ";
}
