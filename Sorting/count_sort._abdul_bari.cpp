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
        if(arr[i]>max){
            max=arr[i];
        }
    }

    int c[max+1];
    //initializing count array with 0
    for(int i=0; i<max+1; i++){
        c[i]=0;
    }
    //storing frequency in count array
    for(int i=0; i<n; i++){
        c[arr[i]]++;
    }

    int i=0,j=0;
    while(i<max+1){
        if(c[i]>0){
            arr[j]=i;
            j++;
            c[i]--;
        }
        else{
            i++;
        }
    }
}

int main()
{
    int arr[1000],n;
    cout<<"Enter n:";
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    countSort(arr,n);
    print(arr,n);
}
