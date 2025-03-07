#include<iostream>
using namespace std;

void print(int *a,int n)
{
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void merge(int *a,int l,int mid,int h)
{
    int i,j,k;
    i=l;
    j=mid+1;
    k=l;
    int temp[h+1];

    while(i<=mid && j<=h){
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }

    for(; i<=mid; i++)
        temp[k++]=a[i];
    for(; j<=h; j++)
        temp[k++]=a[j];

    for(int i=l; i<=h; i++)
        a[i]=temp[i];
}

void mergeSort(int *a,int l,int h)
{
    if(l<h){
      int mid=(l+h)/2; //This logic gives same mid as mid=l+(h-l)/2
       mergeSort(a,l,mid);
       mergeSort(a,mid+1,h);
       merge(a,l,mid,h);
    }

}

int main()
{
    int n,a[100];
    cout<<"Enter n:";
    cin>>n;
    cout<<"Enter elements:";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    mergeSort(a,0,n-1);
    print(a,n);
}
