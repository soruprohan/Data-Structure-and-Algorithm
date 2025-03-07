#include<iostream>
using namespace std;

int main()
{
    int *p=new int;
    *p=25;
    cout<<*p<<endl;
    int *arr=new int[5];

    for(int i=0; i<5; i++){
        *(arr+i)=10*i;
    }
    for(int i=0; i<5; i++){
        cout<<arr[i]<<"\t";
    }
    delete p;
    delete[] arr;
}
