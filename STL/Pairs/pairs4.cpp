#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> a(3),b(3);

    for(auto &value: a){
        cin>>value;
    }
    for(auto &value: b){
        cin>>value;
    }

    for(int i=0; i<3; i++){
        cout<<a[i]<<" ";
        cout<<b[i]<<" ";
    }
   // cout<<endl;
    //printf("\n");
    swap(a,b);

    for(int i=0; i<3; i++){
        cout<<a[i]<<" ";
        cout<<b[i]<<" ";
    }
}
