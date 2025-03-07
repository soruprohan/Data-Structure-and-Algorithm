#include<bits/stdc++.h>
using namespace std;

void print(int arr[],int n)
{
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(int *arr,int lb,int ub)
{
    int pivot=arr[lb];
    int start=lb;
    int end=ub;

    while(start<end){
        while(arr[start]<=pivot)
            start++;
        while(arr[end]>pivot)
            end--;
        if(start<end)
            swap(arr[start],arr[end]);
    }
    swap(arr[end],arr[lb]);

    return end;
}

void quickSort(int *arr,int lb,int ub)
{
    if(lb<ub){
    int loc=partition(arr,lb,ub);

    quickSort(arr,lb,loc-1);
    quickSort(arr,loc+1,ub);
    }
}


int main()
{
    int arr[9]={1,2,3,4,5,6,7,8,9};

    quickSort(arr,0,8);

    print(arr,9);
}
