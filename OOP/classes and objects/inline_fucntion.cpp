#include<iostream>

using namespace std;
int m=10;

class test
{

    public:
        int s;
    static int w;
    inline void setdata();
    void display()
    {
        cout<<s<<endl;
    }
};

void test :: setdata()
{
    s=12;
}

int main()
{
    test ob,ob2;

    ob.setdata();

    ob.display();
    int m=100;

    {
        int m=20;
        cout<<::m<<endl;
    }
}
