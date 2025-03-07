#include<bits/stdc++.h>
using namespace std;


void combi(int ind,int target,int n,int arr[],vector<int> &v,vector<vector<int>> &ans)
{
    if(ind==n){
        if(target==0)
            ans.push_back(v);
        return;
    }

    if(arr[ind]<=target){
        v.push_back(arr[ind]);
        combi(ind+1,target-arr[ind],n,arr,v,ans);
        v.pop_back();
    }
    combi(ind+1,target,n,arr,v,ans);
}
int main()
{
    int n=7;
    int arr[]={10,1,2,7,6,1,5};
    int target=8;
    vector<int> v;
    vector<vector<int>> ans;

    combi(0,target,n,arr,v,ans);

    set<vector<int>> st;

    for(auto it:ans){
        sort(it.begin(),it.end());
        st.insert(it);
    }

    for(auto it:st){
        for(auto it2: it)
            cout<<it2<<" ";
        cout<<endl;
    }
}
