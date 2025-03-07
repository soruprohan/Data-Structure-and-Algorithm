#include<iostream>
using namespace std;

int bSearch(int *a,int start,int end,int target)
{
    int mid=start+(end-start)/2;

    while(start<=end){
        if(a[mid]==target)
            return mid;
        else if(target>a[mid])
            start=mid+1;
        else
            end=mid-1;
    }
    return -1;

}
int main()
{
    int n;  cin>>n;
    int a[100];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<"target:";
    int target; cin>>target;
    if(bSearch(a,0,n-1,target)==-1)
        cout<<"Not present"<<endl;
    else
        cout<<"index:"<<bSearch(a,0,n-1,target)<<endl;
}
