#include<iostream>
using namespace std;

int binarySearch(int *arr,int start,int end,int n)
{
    if(start>end)
        return -1;

    int mid=start+(end-start)/2;

    if(arr[mid]==1 && arr[mid-1]==0)
        return mid;
    else if(arr[mid]==1 && arr[mid-1]==1)
        return binarySearch(arr,start,mid-1,n);
    else
        return binarySearch(arr,mid+1,end,n);

}

int main()
{
    int n,arr[30];
    cout<<"size:";
    cin>>n;

    arr[0]=0;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    int ans=n-binarySearch(arr,1,n,n)+1;
    cout<<"Number if 1's in the binary array is:"<<ans<<endl;
}
