#include<iostream>
using namespace std;

template<class T1=int,class T2=float>
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
    ob=test<>(123,123.45); //same object again constructed by parameterized constructor
                            //but, test<int,float> ob=test<int,float>(123,123.50); this is error,
                            //karon abar decalre kora hocche
    test<int,char>ob2(123,97);

    ob.display();
    ob2.display();
}