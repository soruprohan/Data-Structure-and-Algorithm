#include<iostream>

using namespace std;

class test
{
    static int count;
    int code;
public:
    void setcode();
    void showcode();
    void showcount();
};
void test :: setcode()
{
    code=++count;
}
void test :: showcode()
{
    cout<<"The code of this object is :"<<code<<endl;
}
void test :: showcount()
{
    cout<<"The count is :"<<count<<endl;
}
int test :: count;

int main()
{
    test ob1,ob2,ob3;
    ob1.setcode();
    ob2.setcode();
    ob3.setcode();

    ob1.showcount();

    ob1.showcode();
    ob2.showcode();
    ob3.showcode();
}
