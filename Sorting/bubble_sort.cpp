#include<iostream>
using namespace std;

void bubbleSort(int *arr,int start,int end)
{
    for(int i=start; i<end-1; i++){
        int flag=0;
        for(int j=start; j<end-1-i ; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=1;
            }
        }
        if(flag==0)
            break;      //if not a single swap happens in any one of the passes then it implies the array
                        //is sorted ,no need to check further remaining passes
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
    bubbleSort(arr,0,n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
