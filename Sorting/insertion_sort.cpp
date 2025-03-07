#include<iostream>
using namespace std;

void insertionSort(int *arr,int start,int end)
{
    for(int i=start; i<end; i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}

int main()
{
    int arr[100];
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    insertionSort(arr,0,n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

