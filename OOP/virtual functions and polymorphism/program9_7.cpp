#include<iostream>
using namespace std;

void Add(int i,int j)
{
    cout<<i+j<<endl;
}
void sub(int i,int j)
{
    cout<<i-j<<endl;
}

int main()
{
    void(*ptr)(int,int)=&Add;
    void(*ptr2)(int,int)=&sub;

    (*ptr)(10,20);
    (*ptr2)(20,30);
}