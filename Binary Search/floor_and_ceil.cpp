#include<bits/stdc++.h>
using namespace std;

int ceilSearch(int *arr,int start,int end,int target,int n)
{
    int mid=start+(end-start)/2;

    if(target>arr[n])
        return -1;
    else if(arr[mid]>=target && arr[mid-1]<target)
        return arr[mid];
    else if(arr[mid]<target)
        return ceilSearch(arr,mid+1,end,target,n);
    else
        return ceilSearch(arr,start,mid-1,target,n);

}

int floorSearch(int *arr,int start,int end,int target)
{
    int mid=start+(end-start)/2;

    if(target<arr[1])
        return -1;
    else if(arr[mid]<=target && arr[mid+1]>target)
        return arr[mid];
    else if(arr[mid]<target)
        return floorSearch(arr,mid+1,end,target);
    else
        return floorSearch(arr,start,mid-1,target);

}

int main()
{
    int n,arr[30];
    cout<<"size:";
    cin>>n;

    arr[0]=INT_MIN;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    arr[n+1]=INT_MAX;

    int target;
    cout<<"Target:";
    cin>>target;

    cout<<"Ceil is :"<<ceilSearch(arr,1,n,target,n)<<" "
        <<"floor is :"<<floorSearch(arr,1,n,target)<<endl;
}
