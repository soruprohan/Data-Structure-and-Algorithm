#include<iostream>

using namespace std;

class A
{
    public:
    A(){cout<<"A";}
};
class B:public A
{
    public:
    B(){cout<<"B";}
};
class C:virtual public A
{
    public:
    C(){cout<<"C";}
};
class D: public B
{
    public:
    D(){cout<<"D";}
};
class E:public C
{
    public:
    E(){cout<<"E";}
};
class F: public D, public E
{
    public:
    F(){cout<<"F";}
};

int main()
{
    F ob;
}