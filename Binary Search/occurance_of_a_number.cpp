#include<iostream>
using namespace std;

int firstSearch(int *arr,int start,int end,int target)
{
    if(start>end){
        return -1;
    }
    int mid=start+(end-start)/2;

    if(arr[mid]==target && arr[mid-1]!=target)
        return mid;
    else if(arr[mid]<target)
        return firstSearch(arr,mid+1,end,target);
    else
        return firstSearch(arr,start,mid-1,target);

}

int lastSearch(int *arr,int start,int end,int target)
{
    if(start>end){
        return -1;
    }
    int mid=start+(end-start)/2;

    if(arr[mid]==target && arr[mid+1]!=target)
        return mid;
    else if(arr[mid]>target)
         return lastSearch(arr,start,mid-1,target);
    else
       return lastSearch(arr,mid+1,end,target);
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

    cout<<"Total number of occurrence is: "<<lastSearch(arr,0,n-1,target)-firstSearch(arr,0,n-1,target) +1<<endl;
}

