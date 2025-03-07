#include<iostream>
using namespace std;

template<class T>
void bubble(T *arr,int size)
{
    T temp;
    for(int i=0; i<size-1; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i]>arr[j]){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            }
        }
    }
}
template<class U>
void swap_(U &a,U &b)
{
    a=a+b;
    b=a-b;
    a=a-b;
}

template<class T>
void print(T arr[],int size)
{
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[5]={15,20,10,17,4};
    float far[5]={13.4,14.5,1.6,2.9,14.6,};
    int a=14,b=10;

    cout<<a<<" "<<b<<endl;
    swap_<int,int>(a,b);
    cout<<a<<" "<<b<<endl;

    bubble(arr,5);
    bubble(far,5);

    print(arr,5);
    print(far,5);
}