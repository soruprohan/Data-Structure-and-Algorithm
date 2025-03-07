#include<iostream>
using namespace std;

const int M=47;

int main()
{
    int n;
    cin>>n;
    int fact=1;
    for(int i=2; i<=n; i++){
        fact=(fact*i)%M;
    }
    cout<<fact<<endl;
}