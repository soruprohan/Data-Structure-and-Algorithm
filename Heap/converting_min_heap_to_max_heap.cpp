#include<iostream>
using namespace std;

void insert(int *a,int i)
{
    while(i>0 && a[i]<a[(i-1)/2])
    {
        swap(a[i],a[(i-1)/2]);
        i=(i-1)/2;
    }
}
void print(int *a,int n)
{
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[100],n;
    cout<<"n:";
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];

    for(int i=0; i<n; i++){
        insert(arr,i);
    }
    print(arr,n);
}
