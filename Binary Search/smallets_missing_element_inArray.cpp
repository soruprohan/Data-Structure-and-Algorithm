#include<bits/stdc++.h>
using namespace std;

int binarySearch(int n,int *arr,int start,int end)
{
    int mid=start+(end-start)/2;

    if(start>end && start==n)
        return -1;
    if(start>end)
        return start;
    else if(arr[mid]==mid)
        return binarySearch(n,arr,mid+1,end);
    else
        return binarySearch(n,arr,start,mid-1);
}

int main()
{
    int arr[50],n;
    cout<<"size:";
    cin>>n;

    cout<<"Enter elements starting from 0: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    if(binarySearch(n,arr,0,n-1)!=-1){
        int ans= arr[binarySearch(n,arr,0,n-1)]-1;
        cout<<"smallest missing element is:"<<ans<<endl;
    }
    else
        cout<<"It's a complete array,no missing elements."<<endl;
}
