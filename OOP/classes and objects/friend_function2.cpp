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
    friend int maximum(class1,class2);
};
class class2
{
    int value;
public:
    class2(int x)
    {
        value=x;
    }
    friend int maximum(class1,class2);
};

int maximum(class1 ob1,class2 ob2)
{
    int max=ob1.value>=ob2.value? ob1.value : ob2.value;
    return max;
}

int main()
{
    int a,b;
    cout<<"Enter two values:"<<endl;
    cin>>a>>b;
    class1 ob1(a); //implicit call of constructor
    class2 ob2=class2(b); //explicit call of constructor

    cout<<"Maximum number is:"<<maximum(ob1,ob2)<<endl;
}
