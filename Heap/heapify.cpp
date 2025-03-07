#include<iostream>
using namespace std;

void print(int *a,int n)
{
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void heapify(int *a,int i,int n)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && a[l]>a[largest])
        largest=l;
    if(r<n && a[r]>a[largest])
        largest=r;
    if(largest!=i){
        swap(a[i],a[largest]);
        heapify(a,largest,n);
    }
}

void heapsort(int *a,int n)
{
    for(int i=n/2-1; i>=0; i--)
        heapify(a,i,n);
    for(int i=n-1; i>0; i--){
        swap(a[0],a[i]);
        heapify(a,0,i);
    }
}

int main()
{
    int a[100],n;
    cout<<"Enter n:";
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    heapsort(a,n);
    print(a,n);
}
