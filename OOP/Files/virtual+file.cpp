#include<fstream>
#include<iostream>
using namespace std;

fstream fout("v+f.txt",ios::app);

class A
{
protected:
    int a; 
public:
    A(){}
    A(int a):a(a){}
    virtual void w()
    {
        fout<<"a="<<a<<endl;
    }
};

class B:virtual public A
{
protected:
    int a1; 
public:
    B(){}
    B(int a1):a1(a1){}
    void w()
    {
        fout<<"a="<<a<<endl;
    }
};

class C:virtual public A
{
protected:
    int a2; 
public:
    C(){}
    C(int a2):a2(a2){}
    void w()
    {
        fout<<"a="<<a<<endl;
    }
};
class D:public B,public C
{
    int a3; 
public:
    D(){}
    D(int a3,int a2,int a1,int a):A(a),B(a1),C(a2),a3(a3)
    {

    }
    void w()
    {
       fout<<"a="<<a<<endl;
       fout<<"a1="<<a1<<endl;
       fout<<"a2="<<a2<<endl;
       a3=0726;
       fout<<"a3="<<a3<<endl;
       
    }
};

int main()
{
    A *ptr;
    D ob(1,2,3,4);
    ptr=& ob;

    ptr->w();

}