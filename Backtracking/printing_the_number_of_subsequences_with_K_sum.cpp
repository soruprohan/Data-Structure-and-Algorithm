#include<bits/stdc++.h>
using namespace std;

void printF(int ind,vector<int> &v,int sum,int arr[],int k,int n,int &ct)
{
    if(ind==n){
        if(sum==k){
            ct++;
        }
        return;
    }

    v.push_back(arr[ind]);
    sum+=arr[ind];
    printF(ind+1,v,sum,arr,k,n,ct);

    v.pop_back();
    sum-=arr[ind];
    printF(ind+1,v,sum,arr,k,n,ct);
}

int main()
{
    int n=3,k=2,ct=0;
    int arr[]={1,2,1};

    vector<int> v;

    printF(0,v,0,arr,k,n,ct);
    cout<<ct<<endl;
}
