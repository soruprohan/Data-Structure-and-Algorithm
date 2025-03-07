#include<iostream>

using namespace std;

class Base{
public:
    virtual void f(){
        cout<<"Base f\n";
    }
};
class D1:public Base
{
    public:
    void f(){
        cout<<"D1 f\n";
    }
};
class D2:public D1
{
    public:
    void f(){
        cout<<"D2 f\n";
    }
};
class D3:public D2
{

};
class D4:public D3{

};

int main()
{
    D4 d;
    Base &p=d;
    p.f();
    return 0;
}