#include<iostream>
using namespace std;

int binarySearch(int *arr,int start,int end,int target)
{
    if(start>end){
        return -1;
    }
    int mid=start+(end-start)/2;

    if(target==arr[mid]){
        return mid;
    }
    else if(target<arr[mid]){
         return binarySearch(arr,start,mid-1,target);
    }
    else
        return binarySearch(arr,mid+1,end,target);
}

int main()
{
    int n,arr[30];
    cout<<"size:";
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Target:";
    cin>>target;

    if(binarySearch(arr,0,n-1,target)==-1){
        cout<<"not found"<<endl;
    }
    else
        cout<<"Found at index:"<<binarySearch(arr,0,n-1,target)<<endl;
}
