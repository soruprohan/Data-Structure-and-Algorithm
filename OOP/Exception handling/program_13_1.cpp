#include<iostream>
using namespace std;

int main()
{
    int a;
    int b;
    cout<<"Enter values of A and B:"<<endl;
    cin>>a;
    cin>>b;
    int x=a-b;

    try
    {
        if(x!=0)
        cout<<"Result of a/x is "<<a/x<<endl;
        else
        throw x;
    }
    catch(int i)
    {
        cout<<"Exception caught:Divide by zero."<<endl;
    }
    cout<<"End"<<endl;
    
}