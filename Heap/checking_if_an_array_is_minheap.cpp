#include<iostream>
using namespace std;

int main()
{
    int arr[100];
    int n,flag=0;
    cout<<"Enter size:";
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];

    for(int i=0; i<n; i++){
        int j=2*i+1;
        int k=2*i+2;
        if(j<n && arr[i]> arr[j]){
            flag=1;
            break;
        }
        if(k<n && arr[i]> arr[k]){
            flag=1;
            break;
        }
    }
    if(flag)
        cout<<"no"<<endl;
    else
        cout<<"yes"<<endl;
}
