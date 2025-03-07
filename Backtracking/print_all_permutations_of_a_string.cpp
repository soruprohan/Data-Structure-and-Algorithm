#include<bits/stdc++.h>
using namespace std;

void recurPermute(vector<int> &v,int arr[],int vis[],vector<vector<int>> &ans,int n)
{
    if(v.size()==n){
        ans.push_back(v);
        return;
    }

    for(int i=0; i<n; i++){
        if(!vis[i]){
            v.push_back(arr[i]);
            vis[i]=1;
            recurPermute(v,arr,vis,ans,n);
            vis[i]=0;
            v.pop_back();
        }
    }

}

int main()
{
    int n=3;
    int arr[]={1,2,3};
    vector<int> v;
    int vis[n]={0};
    vector<vector<int>> ans;

    recurPermute(v,arr,vis,ans,n);

    for(auto it:ans){
        for(auto it2:it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
}
