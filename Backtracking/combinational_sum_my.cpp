#include<bits/stdc++.h>
using namespace std;


void func(int *arr,int ind,int sum,int n,vector<int> &ds,int target)
{
    if(ind==n){
        if(target==sum){
            for(auto it:ds){
                cout<<it<<" ";
        }
        cout<<endl;
        }
        return;
    }

    if(sum<=target){
        ds.push_back(arr[ind]);
        sum+=arr[ind];
        func(arr,ind,sum,n,ds,target);
        sum-=arr[ind];
        ds.pop_back();
    }


    func(arr,ind+1,sum,n,ds,target);
}

int main()
{
    int arr[]={2,3,6,7};
    int n=4;
    int target=7;

    vector<int> ds;
    func(arr,0,0,n,ds,target);
    for(auto it:ds){
        cout<<it<<" ";
    }
}


