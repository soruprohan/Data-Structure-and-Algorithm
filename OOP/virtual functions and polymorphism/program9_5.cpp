#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    char *ptr[10]={"books","television","sports","gardening"};

    char *ptr2=new char[25];
    cin>>ptr2;

    int i=0;
    for(; i<4; i++)
    {
        if(!strcmp(ptr2,ptr[i]))
        {
            cout<<"Available"<<endl;
            break;
        }
    }
    if(i==4)
        cout<<"not available"<<endl;
    delete [] ptr2;
}
