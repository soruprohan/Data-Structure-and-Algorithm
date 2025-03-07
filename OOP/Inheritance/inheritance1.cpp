#include<iostream>

using namespace std;

class Base
{
    int a;
public:
    Base(){}
    void set_value(int a)
    {
        this->a=a;
    }
    int get_a()
    {
        return a;
    }
    void show_a()
    {
        cout<<a<<endl;
    } 
};
class Derived : public Base
{
    public:
        Derived(){}
        int get_get_a()
        {
            int A=get_a();
            return A;
        }
};

int main()
{
    Derived D;
    D.set_value(5);
   
    cout<<"Lets get a "<<D.get_get_a()<<endl;
}