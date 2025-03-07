#include<bits/stdc++.h>
using namespace std;

void printF(int ind,vector<int> &ds,int sum,int *arr,int n,int k)
{
    if(ind==n){
        if(sum==k){
        for(auto it:ds)
        cout<<it<<" ";
        cout<<endl;
        }
        return;
    }

    ds.push_back(arr[ind]);
    sum+=arr[ind];
    printF(ind+1,ds,sum,arr,n,k);

    ds.pop_back();
    sum-=arr[ind];
    printF(ind+1,ds,sum,arr,n,k);
}

int main()
{
    int arr[]={3,1,2};
    int n=3;
    vector<int> ds;
    int k=3;
    printF(0,ds,0,arr,n,k);


}
