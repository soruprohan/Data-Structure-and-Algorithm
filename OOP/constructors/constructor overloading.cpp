#include<iostream>

using namespace std;
class complex
{
    float real;
    float img;
public:
    complex(){};

    complex(float real,float img=2.5)
    {
        this->real=real;
        this->img=img;
    }

    friend complex sum(complex,complex);
    friend void show(complex);
};
complex sum(complex ob1,complex ob2)
{
    complex ob3;
    ob3.real=ob1.real+ob2.real;
    ob3.img=ob1.img+ob2.img;

    return ob3;
}
void show(complex xx)
{
    cout<<xx.real<<" + "<<xx.img<<"i"<<endl;
}
int main()
{
    complex ob1;
    complex ob2(2.4);
    complex ob3(6.7,9.1);
    ob1=sum(ob2,ob3);

    show(ob2);
    show(ob3);
    show(ob1);
}

