#include<iostream>
using namespace std;

template<class T,class U>

void test(void)
{
    cout<<"type T"<<endl;
    cout<<"type U"<<endl;
}

int main()
{
    test<int,float>();
}
