#include<bits/stdc++.h>
using namespace std;

void printF(int ind,vector<int> &ds,int sum,int arr[],int K,int n)
{
    if(ind==n){
        if(sum==K){
            for(auto it:ds){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return;
    }

    ds.push_back(arr[ind]);
    sum+=arr[ind];
    printF(ind+1,ds,sum,arr,K,n);

    ds.pop_back();
    sum-=arr[ind];
    printF(ind+1,ds,sum,arr,K,n);
}

int main()
{
    int n=3;
    int arr[]={1,2,1};
    int K=2;
    vector<int> ds;

    printF(0,ds,0,arr,K,n);
}
