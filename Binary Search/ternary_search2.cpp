#include<iostream>
using namespace std;

int ternarySearch(int *arr,int l,int r,int key)
{
    if(l>r)return -1;

    int mid1=l+(r-l)/3;
    int mid2=r-(r-l)/3;

    if(key==arr[mid1])
        return mid1;
    if(key==arr[mid2])
        return mid2;
    if(key<arr[mid1])
        return ternarySearch(arr,l,mid1-1,key);
    if(key>arr[mid2])
        return ternarySearch(arr,mid2+1,r,key);
    else
        return ternarySearch(arr,mid1+1,mid2-1,key);
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

    if(ternarySearch(arr,0,n-1,target)==-1){
        cout<<"not found"<<endl;
    }
    else
        cout<<"Found at index:"<<ternarySearch(arr,0,n-1,target)<<endl;
}
