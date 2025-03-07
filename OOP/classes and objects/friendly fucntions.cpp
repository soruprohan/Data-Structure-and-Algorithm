#include<iostream>
using namespace std;

class test
{
    int a;
    int b;
public:
    void setvalue(int,int);
    friend float mean(test &);
};
void test :: setvalue(int x,int y)
{
    this->a =x;
    this->b=y;
}
float mean(test &ob1)
{
    float mean=(float)(ob1.a+ob1.b)/2;
    return mean;
}
int main()
{
    test ob1;
    int x,y;
    cout<<"Enter two integers:"<<endl;
    cin>>x>>y;

    ob1.setvalue(x,y);
    cout<<"Mean is "<<mean(ob1)<<endl;
}
