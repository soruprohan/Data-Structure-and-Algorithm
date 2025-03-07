#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int Hash[13]={0};
    for(int i=0; i<n; i++){
        Hash[arr[i]]++;
    }

    int q;
    cout<<"Enter no of queries:";
    cin>>q;

    while(q--){
        cout<<"Enter element:";
        int x;
        cin>>x;
        cout<<Hash[x]<<endl;
    }
}
