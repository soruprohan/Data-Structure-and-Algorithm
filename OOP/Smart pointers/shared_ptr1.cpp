#include<iostream>
#include<memory>

using namespace std;

int main()
{
    shared_ptr<int> p1=make_shared<int>(100);

    cout<<p1.use_count()<<endl;

    shared_ptr<int>p2{p1};

    cout<<p2.use_count()<<endl;
    cout<<p1.use_count()<<endl;

    p2.reset();

    cout<<p1.use_count()<<endl;
    cout<<p2.use_count()<<endl;

    shared_ptr<int> p3=p1;
    cout<<*p3<<endl;
    cout<<p3.use_count()<<endl;
}