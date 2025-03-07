#include<iostream>
using namespace std;

class complex
{
    float real;
    float img;
public:
    complex(){}; //default constructor
   complex(float real,float img)
   {
       this->real=real;
       this ->img=img;
   }
   friend complex add(complex,complex);
   void show()
   {
       cout<<real<<" + i "<<img<<endl;
   }
};
complex add(complex ob1,complex ob2)
{
    complex ob3;
    ob3.real=ob1.real+ob2.real;
    ob3.img=ob1.img+ob2.img;
    return ob3;
}
int main()
{
   complex cc;

   complex aa(12.5,13.4);
   complex bb(34.6,7.2);
   cc=add(aa,bb);

   aa.show();
   bb.show();
   cout<<"After adding:"<<endl;
   cc.show();
}
