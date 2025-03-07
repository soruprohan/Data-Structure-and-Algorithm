#include<iostream>
using namespace std;

template<class X>
class test
{
    X data1,data2;
public:
    test(){}
    test(X data1, X data2):data1(data1),data2(data2)
    {

    }
     void display();
     X maximum();
};

template<class X>
void test<X>::display()
{
    cout<<"Maximum number is "<<maximum()<<endl;
}
template<class X>
X test<X> :: maximum()
{
    if(data1>data2)
        return data1;
    else 
        return data2;
}

int main()
{
    test<int> ob(10,20);

    ob.display();
}