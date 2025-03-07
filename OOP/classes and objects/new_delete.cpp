#include<iostream>
#include<iomanip>

using namespace std;

class test
{
    int x,y;
    public:
    test(){}
    test(int x,int y): x{x},y{y}{}
    friend ostream& operator<<(ostream&,test);
};
ostream& operator<<(ostream& COUT, test ob)
{
    cout<<"X="<<ob.x<<setw(7)<<" Y="<<ob.y<<endl;
    return COUT;
}

int main()
{
    test ob(10,20);
    cout<<ob;
    test *ptr= new test[10];
    int a=10,b=100;
    for(int i=0; i<5; i++){
       ptr[i]=test(a,b);
       cout<<ptr[i];
       a+=10;
       b+=100;
    }
    delete ptr;
}