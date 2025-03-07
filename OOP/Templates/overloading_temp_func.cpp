#include<iostream>
using namespace std;

template<class T>
T get(T a)
{
    cout<<"tenplate T"<<endl;
    return a;
}
template<class T,class U>
void get(T a,U b)
{
    cout<<"Template T_U"<<endl;
    cout<<a<<" "<<b<<endl;
}

int get(int a)
{
    cout<<"Normal int"<<endl;
    return a;
}

int main()
{
    cout<<get(10)<<endl;
    cout<<get(10.5)<<endl;
    get(10,20);
}

