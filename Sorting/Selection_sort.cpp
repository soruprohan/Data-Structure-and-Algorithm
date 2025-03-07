#include<iostream>
using namespace std;

void selectionSort(int *arr,int start,int end)
{
    for(int i=start; i<end-1; i++){
        int min=i;

        for(int j=i; j<end; j++){
           if(arr[j]<arr[min])
                min=j;
        }
        swap(arr[i],arr[min]);
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
    selectionSort(arr,0,n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
