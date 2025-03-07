#include<iostream>
using  namespace std;

void test(int x)
{
    try{
        if(x==1) throw x;
        else if(x==0)
            throw 'x';
        else if(x==-1)
            throw 1.0;

        cout<<"End of try block"<<endl;
    }
    catch(char c)
    {
        cout<<"caught a char"<<endl;
    }
    catch(int i)
    {
        cout<<"caught an int"<<endl;
    }
    catch(double d) //ekhane 1.0 ke double hisebe treat kortese,float boshaile runtime error ashe
    {
        cout<<"caught a double"<<endl;
    }
    cout<<"End of try catch sytem"<<endl;
}

int main()
{
    cout<<"Testting multiple cases"<<endl;
    test(1);
    test(0);
    test(-1);
    test(2);

    return 0;
}