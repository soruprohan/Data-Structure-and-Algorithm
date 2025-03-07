#include<iostream>
using namespace std;

namespace name1
{
    double x=4.56;
    int m=10;

    namespace name2
    {
        double y=1.23;
    }
}
namespace 
{
    int m=200;
}

int main()
{
    cout<<"x= "<<name1::x<<endl;
    cout<<"m= "<<name1::m<<endl;
    cout<<"y= "<<name1::name2::y<<endl;
    cout<<"m= "<<m<<endl;
}