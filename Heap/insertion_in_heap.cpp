#include<iostream>
using namespace std;

void insert(int *arr, int i)
{
    while(i>1 && arr[i] > arr[i/2]){
        swap(arr[i],arr[i/2]);
        i=i/2;
    }
}

//this is abdul bari method of inserting
void insert2(int *arr,int i)
{
    int temp=arr[i];
    while(i>1 && arr[i]>arr[i/2]){
        arr[i]=arr[i/2];
        i=i/2;
    }
    temp=arr[i];
}

void print(int *arr,int n)
{
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cout<<"Enter size:";
    cin>>n;
    int arr[n+1];

    cout<<"Enter elements:"<<endl;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    for(int i=1; i<=n; i++){
        insert(arr,i);
        //insert2(arr,i);
    }
    print(arr,n);
}
