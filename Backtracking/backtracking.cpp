#include<iostream>
using namespace std;

void func(int i,int n)
{
    if(i>n)
        return;
    else{
        func(i+1,n);
        cout<<i<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    func(1,n);
}
