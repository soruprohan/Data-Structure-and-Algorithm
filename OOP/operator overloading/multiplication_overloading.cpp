#include<iostream>

using namespace std;

class product
{
    float num;
public:
    product(){};
    product(float);
    friend void display(product &);

    friend product operator*(product ,product &);
};
product :: product(float num)
{
    this ->num=num;
}
void display(product &ob)
{
    cout<<ob.num<<endl;
}

product operator*(product ob1,product &ob2)
{
    return product(ob1.num*ob2.num);
}

int main()
{
    product ob(5.5);
    product obx;
    obx=3*ob;

    display(ob);
    display(obx);
}
