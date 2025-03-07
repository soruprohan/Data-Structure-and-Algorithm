#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<[](int x,int y){return x+y;}(2,3)<<endl;

    cout<<"Enter two numbers:"<<endl;
    int a,b;
    cin>>a>>b;

    auto sum=[](int x,int y){return x+y;};

    cout<<sum(a,b);
}
