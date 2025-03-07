#include<iostream>

using namespace std;

class sum
{
    float num;
    int ok=10;
public:
    sum(){};
    sum(float num)
    {
        this -> num=num;
    }
    void display();
    sum operator+(sum &);
};

void sum :: display()
{
    cout<<num<<endl;
}
sum sum :: operator+(sum &ob)
{
//    sum temp;
//    temp.num=num+ob.num;
//    return temp;
    return sum(num+ob.num);
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
    ob6=ob1.operator+(ob2);

    ob3.display();
    ob6.display();
}

