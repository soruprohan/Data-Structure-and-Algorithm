#include<iostream>

using namespace std;

class sum
{
    float num;
public:
    sum(){};
    sum(float num)
    {
        this -> num=num;
    }
    void display();
    friend sum operator+(sum &,sum &);
};

void sum :: display()
{
    cout<<num<<endl;
}
sum operator+(sum &ob1,sum& ob2)
{
    return sum(ob1.num+ob2.num);
}

int main()
{
    float x,y;
    cin>>x>>y;

    sum ob1(x);
    sum ob2(y);
    sum ob3;

    sum ob4(x);
    sum ob5(y);
    sum ob6;

    ob3=ob1+ob2;
    ob6=operator+(ob4,ob5);

    ob3.display();
    ob6.display();
}

