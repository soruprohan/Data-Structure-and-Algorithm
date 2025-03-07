#include<iostream>
#include<typeinfo>

using namespace std;

class Base
{
    virtual void f(){}
};
class D:public Base{};

void w(Base &ob)
{
    cout<<typeid(ob).name()<<endl;
}

int main()
{
    Base *bp,bob;

    D dob;
    w(bob);
    w(dob);
}