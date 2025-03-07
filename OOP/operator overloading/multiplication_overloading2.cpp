#include<iostream>

using namespace std;

class product
{
    float num;
public:
    product(){};
    product(float);
    friend void display(product &);

    product operator*(product);
};
product :: product(float num)
{
    this ->num=num;
}
void display(product &ob)
{
    cout<<ob.num<<endl;
}

product product :: operator*(product ob1)
{
    return product(num*ob1.num);
}

int main()
{
    product ob(5.5);
    product obx;

    obx=ob*3; //obx=3*ob ; is not allowed because we called it using member function

    display(ob);
    display(obx);
}

