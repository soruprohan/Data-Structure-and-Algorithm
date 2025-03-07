#include<iostream>
using namespace std;

class X
{
protected:
    int x;
public:
    virtual void show_x()
    {
        x=10;
        cout<<"x is "<<x<<endl;
    } //pure virtual function
};
class first :public X
{
public:
    void show_x()
    {
        cout<<"ok vai,x is "<<x<<endl;
    }
};
class second :public X
{
public:
    void show_x()
    {
        cout<<"no vai,x is "<<x<<endl;
    }
};

int main()
{
    first ob1;
    ob1.show_x();
    second ob2;
    ob2.show_x();
}