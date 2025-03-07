#include<iostream>

using namespace std;

class product
{
    float real;
    float img;
public:
    product(){};
    product(float,float);
    friend void display(product &);

    friend product operator*(product ,product );
};
product :: product(float real,float img)
{
    this ->real=real;
    this ->img=img;
}
void display(product &ob)
{
    cout<<ob.real<<" + "<<ob.img<<" i"<<endl;
}

product operator*(product ob1 ,product ob2)
{
    product temp;
    temp.real=ob1.real*ob2.real-ob1.img*ob2.img;
    temp.img=ob1.real*ob2.img+ob1.img*ob2.real;

    return temp;
}

int main()
{
    product ob1(5.5,6.7);
    product ob2(3.4,5.6);
    product ob3;

    ob3=ob1*ob2;

    display(ob1);
    display(ob2);

    cout<<"Product is :";
    display(ob3);
}

