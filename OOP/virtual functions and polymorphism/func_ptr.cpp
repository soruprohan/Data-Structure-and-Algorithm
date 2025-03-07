#include<iostream>

using namespace std;

class A
{
    int a,b;
    public:
    void set_data(int a,int b)
    {
        this->a=a;
        this->b=b;
    }
    void show()
    {
        cout<<"a="<<a<<" b="<<b<<endl;
    }
    friend int sum(A ob);
};

int sum(A ob)
{
    int A:: *pa=& A:: a;
    int A:: *pb=& A:: b;
    A *pob=&ob;

    int s= ob.*pa+ pob->*pb;
    return s;
}
int main()
{
    A ob;
    void(A:: *ptr)(int ,int)=& A::set_data;

    (ob.*ptr)(10,20);

    void (A:: *ptr3)()=& A:: show;
    (ob.*ptr3)();
    int(*ptr2)(A )=& sum;
    cout<<(*ptr2)(ob)<<endl;
}