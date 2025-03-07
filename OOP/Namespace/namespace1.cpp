#include<iostream>

//using namespace std;

namespace type
{
    int m=100;
    void func()
    {
        std::cout<<"Type space"<<std::endl;
    }
}
 
void func2();

int main()
{
   using namespace type;

std::cout<<"ok"<<std::endl;

   {
    int m=80;
    std::cout<<m<<std::endl;
   }
    //m=10;
    std::cout<<m<<std::endl;

    func();
    func2();
}

void func2()
{
    std::cout<<type::m<<std::endl; //type::m dite hobe
}

