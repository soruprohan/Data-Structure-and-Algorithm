#include<iostream>

using namespace std;

class sum
{
    float real;
    float img;
public:
    sum(){};
    sum(float,float);
    friend void display(sum);

    friend sum operator+(sum ,sum );
};

sum :: sum(float real,float img)
{
    this -> real=real;
    this -> img=img;
}
void display(sum ob)
{
    cout<<ob.real<<" + "<<ob.img<<" i"<<endl;
}
sum operator+(sum ob1,sum ob2)
{
    return sum((ob1.real+ob2.real),(ob1.img+ob2.img));
}

int main()
{
    sum ob1(2.3,5.7);
    sum ob2(3.4,5.8);

    sum ob3;
    ob3=ob1+5;

    display(ob1);
    display(ob2);
    display(ob3);

    ob3= operator+(ob3,ob3);

    display(ob3);
}
