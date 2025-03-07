#include<iostream>

using namespace std;

class class2; //forward declaration
class class1
{
    int value;
public:
    class1(int x)
    {
        value=x;
    }
    friend void swap(class1 &,class2 &);
};
class class2
{
    int value;
public:
    class2(int);
    friend void swap(class1 &,class2 &);
};

class2 :: class2(int x)
{
    this->value=x;
}

void swap(class1 &ob1,class2 &ob2)
{
    /*int temp=ob1.value;
    ob1.value=ob2.value;
    ob2.value=temp
    */

    //another logic without using a third variable

    ob1.value=ob1.value+ob2.value;
    ob2.value=ob1.value-ob2.value;
    ob1.value=ob1.value-ob2.value;
    cout<<ob1.value<<" "<<ob2.value<<endl;
}
int main()
{
    int x,y;
    cout<<"Enter two numbers you want to swap:"<<endl;
    cin>>x>>y;
    class1 ob1(x);
    class2 ob2(y);
    swap(ob1,ob2);
}
