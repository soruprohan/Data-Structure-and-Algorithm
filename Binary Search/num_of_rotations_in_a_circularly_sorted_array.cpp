#include<iostream>
using namespace std;

int binarySearch(int *arr,int start,int end)
{
    if(start>end)   return -1;

    int mid=start+(end-start)/2;

    if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1])
        return binarySearch(arr,start,mid-1);
    else
        return mid;
}
int main()
{
     int n,arr[30];
    cout<<"size:";
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"Number of rotation: "<<binarySearch(arr,0,n-1)+1<<endl;
}
