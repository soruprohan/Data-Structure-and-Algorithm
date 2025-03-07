#include<iostream>

using namespace std;

class A
{
    public:
    A(){cout<<"A";}
};
class B:virtual public A
{
    public:
    B(){cout<<"B";}
};
class C:public A
{
    public:
    C(){cout<<"C";}
};
class D: public B,public C
{
    public:
    D(){cout<<"D";}
};

int main()
{
    D ob;
}