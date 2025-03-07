#include<iostream>
using namespace std;

class base
{
    public:
    void display()
    {
        cout<<"Display base"<<endl;
    }
    void show()
    {
        cout<<"Show base"<<endl;
    }
};
class derived: public base
{
    public:
    virtual void display()
    {
        cout<<"Display derived"<<endl;
    }
    void show()
    {
         cout<<"Show derived"<<endl;
    }
};
class derived2: public derived
{
    public:
    virtual void display()
    {
        cout<<"Display derived2"<<endl;
    }
    void show()
    {
         cout<<"Show derived2"<<endl;
    }
};

int main()
{
    base b;
    derived d;

    base *bptr=&b;
    bptr->display();
    bptr->show();

    bptr=&d;
    bptr->display();
    bptr->show();

    derived2 d2;
    base *dptr=&d2;

    dptr->display();
    dptr->show();
}