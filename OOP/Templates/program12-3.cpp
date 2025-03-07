#include<iostream>
using namespace std;

template<class T1,class T2>
class test
{
    T1 x;
    T2 y;
public:
    test()
    {
        cout<<"Default constructor called"<<endl;
    }
    test(T1 x, T2 y)
    {
        cout<<"Parameterized constructor called"<<endl;
        this->x=x;
        this->y=y;
    }
    ~test(){cout<<"Destructor called"<<endl;}

    void display()
    {
        cout<<"x="<<x<<" & y="<<y<<endl;
    }
};

int main()
{
    test<int,float> ob; //default constructor called
    ob=test<int,float>(123,123.50); //same object again constructed by parameterized constructor
                                    //but, test<int,float> ob=test<int,float>(123,123.50); this is error,
                                    //karon abarr declare kora hocche
                                    //abar, ob=test<int,char>(123,'a'); etao error karon vitore type eki thaka lagbe
                        
    test<int,char>ob2(123,97);

    ob.display();
    ob2.display();
}