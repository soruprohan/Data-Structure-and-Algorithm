#include<iostream>
using namespace std;

class M
{
protected:
    int m;
public:
    void set_m(int m){this ->m=m;}
    void display()
    {
        cout<<"m= "<<m<<endl;
    }
};
class N
{
protected:
     int n;
    public:
    void set_n(int n){this ->n=n;}
    void display()
    {
        cout<<"n="<<n<<endl;
    }
};
class P: public M,public N
{
    public:
    void display()
    {
        cout<<"m,n= "<<m<<","<<n<<endl;
    }
};

int main()
{
    P p;
    p.set_m(7);
    p.set_n(9);

    p.M::display();
    p.N::display();
    p.display();
}