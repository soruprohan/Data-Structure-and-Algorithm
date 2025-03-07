#include<iostream>
using namespace std;

class item
{
    int number;
    float price;
public:
    void getdata(int a,float b);
    void putdata(void);
};

void item :: getdata(int a,float b)
{
    number=a;
    price=b;
}
void item :: putdata(void)
{
    cout<<"Number : "<<number<<endl;
    cout<<"Price  : "<<price<<endl;
}
int main()
{
    item aa,bb;
    aa.getdata(10,500.6);
    aa.putdata();

    bb.getdata(20,467.8);
    bb.putdata();
}
