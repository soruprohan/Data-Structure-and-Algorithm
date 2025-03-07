#include<iostream>

using namespace std;

class test
{

public:
    int val;
    test(int);
    void setvalue(test &);
    void showvalue();
};

test :: test(int val)
{
    this->val=val;
}
void test :: setvalue(test &ob1)
{
    ob1.val=69;
}

void test :: showvalue()
{
    cout<<val<<endl;
}
int main()
{
    test ob1=test(42);
    ob1.showvalue();
    ob1.setvalue(ob1);
    ob1.showvalue();
}


