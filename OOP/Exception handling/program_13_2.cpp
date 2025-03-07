#include<iostream>
using namespace std;


void divide(int x,int y)
{
    if(y!=0)
        cout<<"x/y ="<<x/y<<endl;
    else
        throw y;
}
int main()
{
    int x,y;
    try
    {
        divide(13,6);
        divide(12,0);
    }
    catch(int i)
    {
        cout<<"Exception caught"<<endl;
    }
    cout<<"END"<<endl;

}