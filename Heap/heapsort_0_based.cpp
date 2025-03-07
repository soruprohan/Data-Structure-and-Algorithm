#include<iostream>
using namespace std;

void print(int *a,int n)
{
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void insert(int *a,int i)
{

    while(i>0 && a[i]>a[(i-1)/2]){
        swap(a[i],a[(i-1)/2]);
        i=(i-1)/2;
    }
}
void del(int *a,int n)
{
    swap(a[0],a[n]);
    int i=0;
    int j=i*2+1;

    while(j < n-1){
        if(a[j+1]> a[j])
            j=j+1;
        if(a[j]>a[i]){
            swap(a[i],a[j]);
            i=j;
            j=i*2+1;
        }
        else
            break;
    }
}

void heapsort(int *a,int n)
{
    for(int i=0; i<n; i++)
        insert(a,i);
    for(int i=n-1; i>0; i--){
        del(a,i);
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
