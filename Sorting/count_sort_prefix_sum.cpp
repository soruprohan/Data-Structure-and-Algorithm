#include<iostream>
using namespace std;

void print(int *arr,int n)
{
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void countSort(int *arr,int n)
{
    //finding max value
    int max=INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]>max)
            max=arr[i];
    }
    //initializing count array with 0
    int c[max+1]={0};
    //storing frequency in count array
    for(int i=0; i<n; i++){
        c[arr[i]]++;
    }
    //finding prefix sum
    for(int i=1; i<max+1; i++){
        c[i]=c[i-1]+c[i];
    }
    int output[n]={0};
    // Finding the index of each element of the original array in count array, and
    // placing the elements in output array
    //this loop is done in reverse order to maintain stability
    for(int i=n-1; i>=0; i--){
        output[c[arr[i]]-1]=arr[i];
        c[arr[i]]--;
    }
    // Copying the sorted elements into original array
    for (int i=0; i<n; i++) {
        arr[i]=output[i];
    }
}

int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    countSort(arr,n);
    print(arr,n);
}
