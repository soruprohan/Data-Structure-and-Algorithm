#include<iostream>

using namespace std;

void test(int x)
{
    try{
        if(x==0)
        throw x;
        if(x==1)
        throw 'x';
        if(x==-1)
        throw 1.0;
        cout<<"End of try block"<<endl;
    }
   
    catch(int i)
    {
        cout<<"int catch korse"<<endl;
    }

     catch(...){
        cout<<"Caught an exception"<<endl;
    }
    
    cout<<"End of try catch"<<endl;
}

int main()
{
    test(-1);
}