#include<iostream>
#include<memory>

using namespace std;

namespace classes 
{
    class A
    {
        int a;
        public:
        A(int a):a(a){}
        void display()
        {
            cout<<"a is "<<a<<endl;
        }
    };
}

int main()
{
    classes:: A ob(12);
    ob.display();

    shared_ptr<classes::A> p= make_shared<classes::A>(19);

    shared_ptr<classes::A>p2{p};

    shared_ptr<classes::A>p3=p2;

    cout<<p3.use_count()<<endl;

    p->display();

    p.reset();
    
    if(!p)
    {
        cout<<"p is null now"<<endl;
    }

    cout<< p.use_count()<<endl
        <<p2.use_count();
}