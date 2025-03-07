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
    int arr[100];

    insert(arr,1,30);
    insert(arr,2,20);
     insert(arr,3,15);
      insert(arr,4,5);
       insert(arr,5,10);
        insert(arr,6,12);
         insert(arr,7,6);
          insert(arr,8,40);
           insert(arr,9,35);

    print(arr,9);
}

