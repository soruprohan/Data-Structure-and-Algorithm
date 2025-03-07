#include<iostream>

using namespace std;

namespace namespace1
{
    void func()
    {
        cout<<"This is namespace 1"<<endl;
    }
    namespace namespace2
    {
        void func()
        {
            cout<<"This is namespace 2"<<endl;
        }
    }
}


int main()
{
    using namespace namespace1::namespace2;
    func();

   /* using namespace namespace1;
    func();*/ //won't work
    namespace1::func();
   
}
 