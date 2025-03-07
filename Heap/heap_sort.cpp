#include<iostream>
using namespace std;

void print(int *arr,int n)
{
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insert(int *arr,int i,int elem)
{
    arr[i]=elem;
    while(i>1 && arr[i]>arr[i/2]){
        swap(arr[i],arr[i/2]);
        i=i/2;
    }
}

void del(int *arr,int n)
{
    int x,i,j;
    x=arr[1];
    arr[1]=arr[n];

    i=1,j=2*i;
    while(j < n-1){
       if(arr[j+1] > arr[j])
            j=j+1;
       if(arr[i] < arr[j]){
            swap(arr[i],arr[j]);
            i=j;
            j=2*j;
       }
       else
            break; //kono ekbar swap na hoilei bujhte hobe amra amader max heap peye gesi
    }

    arr[n]=x;      //root or largest element inserted at the last of the heap
}

void heapsort(int *arr,int n)
{
    for(int i=n; i>=1; i--){
        del(arr,i);
    }
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
    print(arr,n);
    heapsort(arr,n);
    print(arr,n);
}

