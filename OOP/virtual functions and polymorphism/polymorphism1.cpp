#include<iostream>
using namespace std;

int main()
{
    int a,*ptr,**ptr2;
    ptr=&a;
    ptr2=&ptr;
    cout<<"&a="<<ptr<<endl;
   // system("cls");
    cout<<"&ptr="<<ptr2<<endl;
}