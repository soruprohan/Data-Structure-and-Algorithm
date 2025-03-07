#include<bits/stdc++.h>
using namespace std;

void rev(int *a,int i,int n)
{
    if(i>=n-i)
        return;
    swap(a[i],a[n-i]);
    rev(a,i+1,n);
}
int main()
{
    int n=6;
    int a[]={1,2,3,4,5,6};
    rev(a,0,n-1);
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
}
