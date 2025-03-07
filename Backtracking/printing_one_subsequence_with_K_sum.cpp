#include<bits/stdc++.h>
using namespace std;

bool flag=true;

void printF(int ind,vector<int> &v,int arr[],int sum,int k,int n)
{
    if(ind==n){
        if(k==sum && flag==true){
            flag=false;
            for(auto it:v){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return;
    }

    v.push_back(arr[ind]);
    sum+=arr[ind];
    printF(ind+1,v,arr,sum,k,n);

    v.pop_back();
    sum-=arr[ind];
    printF(ind+1,v,arr,sum,k,n);
}

int main()
{
    int n=3;
    int arr[]={1,2,1};
    vector<int> v;
    int k=2;

    printF(0,v,arr,0,k,n);
}
