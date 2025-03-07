#include<bits/stdc++.h>
using namespace std;

float binarySearch(int n,int start,int end)
{
    int mid=start+(end-start)/2;
    if(floor(sqrt(n))== mid)
        return mid;
    else if(floor(sqrt(n))< mid)
        return binarySearch(n,start,mid-1);
    else
        return binarySearch(n,mid+1,end);
}

int main()
{
    int n;
    cout<<"Enter number:";
    cin>>n;

    int ans=binarySearch(n,0,n);

    cout<<ans<<endl;
}
