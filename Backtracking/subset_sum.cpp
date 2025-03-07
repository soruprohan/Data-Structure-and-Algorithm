#include<bits/stdc++.h>
using namespace std;

void printF(int ind,int arr[],vector<int> &ds,int n,int sum,int target)
{
    if(ind==n){
        if(sum==target){
            for(auto it:ds)
                cout<<it<<" ";
            cout<<endl;
        }
        return;
    }

    ds.push_back(arr[ind]);
    sum+=arr[ind];
    printF(ind+1,arr,ds,n,sum,target);

    ds.pop_back();
    sum-=arr[ind];
    printF(ind+1,arr,ds,n,sum,target);
}

int main()
{
    int n=3;
    int arr[]={3,1,2};

    vector<int> ds;
    int target;
    cin>>target;

    printF(0,arr,ds,n,0,target);
    
}
