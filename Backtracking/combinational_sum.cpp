#include<bits/stdc++.h>
using namespace std;

void combi(int ind,vector<int> &ds,int arr[],int target,vector<vector<int>> &ans,int n)
{
    if(ind==n){
        if(target==0){
            ans.push_back(ds);
        }
        return;
    }

    if(arr[ind]<=target){
        ds.push_back(arr[ind]);
        combi(ind,ds,arr,target-arr[ind],ans,n);

        ds.pop_back();
    }

    combi(ind+1,ds,arr,target,ans,n);
}
int main()
{
    vector<int> ds;
    int n=4;
    int arr[]={2,3,6,7};
    int target=7;

    vector<vector<int>> ans;

    combi(0,ds,arr,target,ans,n);

    for(auto it:ans){
        for(auto it2:it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
}
