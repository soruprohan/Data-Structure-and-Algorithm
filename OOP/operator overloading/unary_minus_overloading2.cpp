#include<iostream>

using namespace std;

class unary
{
    float num;
public:
    unary(){};
    unary(float num)
    {
        this -> num=num;
    }
    void display();
    void operator-();
};

void unary :: display()
{
    cout<<num<<endl;
}
void unary:: operator-()
{
    num=-num;
}

int main()
{
    unary ob1(20.5);
    unary ob2=unary(40.7);
    float n;
    cout<<"Enter a number:"<<endl;
    cin>>n;
    unary ob3(n);

    -ob1;
    -ob2;
    -ob3;

    ob1.display();
    ob2.display();
    ob3.display();

}

