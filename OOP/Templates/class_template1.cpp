#include<iostream>
using namespace std;

template<class X,class Y,class Z>
class test
{
    X data1;
    Y data2;
    Z data3;
public:
     void display();
};

template<class X,class Y,class Z>
void test<X,Y,Z> :: display()
{
        cout<<"Template class"<<endl;
}

int main()
{
    test<int,float,char> ob;

    ob.display();
}