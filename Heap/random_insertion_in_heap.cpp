#include<iostream>
using namespace std;

void insert(int *arr,int n,int elem)
{
    arr[n]=elem;
    int i=n;
    while(i>1 && arr[i]>arr[i/2]){
        swap(arr[i],arr[i/2]);
        i=i/2;
    }
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
    int arr[100];

    cout<<"Enter elements:"<<endl;
    for(int i=1; i<=n; i++){
        int elem;
        cin>>elem;
        insert(arr,i,elem);
    }
    insert(arr,++n,35);
    print(arr,n);
}
