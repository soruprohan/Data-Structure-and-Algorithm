#include<bits/stdc++.h>
using namespace std;

int binarySearch(int *arr,int start,int end,int target)
{
    if(start>end) return -1;

    int mid=(start+end)/2;

    if(target==arr[mid]) return mid;
    else if(target>arr[mid])
        return binarySearch(arr,mid+1,end,target);
    else
        return binarySearch(arr,start,mid-1,target);
}

int main()
{
    int n;
    int arr[]={10,20,30,40,50,60,70,80,90};
    n=sizeof(arr)/sizeof(int);

    int target;
    cout<<"To search:";
    cin>>target;

    int foundIndex=binarySearch(arr,0,n-1,target);

    if(foundIndex==-1)
        cout<<"The number is not in the array."<<endl;
    else
        cout<<"The number is at index position:"<<foundIndex<<endl;
}
