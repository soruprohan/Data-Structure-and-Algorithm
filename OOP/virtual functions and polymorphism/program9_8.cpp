#include<iostream>
using namespace std;

class A
{
    int a,b;
    public:
    void set_data(int a,int b)
    {
        this->a=a;
        this->b=b;
    }
    void show()
    {
        cout<<"a="<<a<<" b="<<b<<endl;
    }
};

int main()
{
    A ob;

    A *ptr=new A[10];

    ptr[1].set_data(10,30);
    (ptr+1)->show();

    A *ptr2=new A;
    ptr2[0].set_data(10,40);

    ptr2[0].show();
}