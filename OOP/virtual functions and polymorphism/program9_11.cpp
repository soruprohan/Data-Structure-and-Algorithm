#include<iostream>
using namespace std;

class base
{
    public:
    int b;
    void show()
    {
        cout<<"b="<<b<<endl;
    }
};
class derived :public base
{
public:
    int d;
    void show()
    {
        cout<<"b="<<b<<endl;
        cout<<"d="<<d<<endl;
    }
};

int main()
{
    base *bptr;
    base ob;
    bptr=&ob;

    bptr->b=100;
    bptr->show();

    derived od;
    bptr=&od;
    bptr->b=200;
   // bptr->d=300; //won't work
    bptr->show();

    derived *dptr=&od;
    dptr->show();
    dptr->d=500;
    dptr->show();

    ((derived *)bptr)->show();

}