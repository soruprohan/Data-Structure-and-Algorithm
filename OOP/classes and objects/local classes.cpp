#include<iostream>
using namespace std;

int global=130;

void myFunction()
{
    int x = 10; // 'x' is an automatic local variable
    static int y=20;

    class LocalClass
    {
        // static int z;
    public:
        void someFunction()
        {
            // You cannot use 'x' here because it's an automatic local variable
            // and local classes cannot access it.
            int a= :: global;
            int b= y;
            //int c=x;
        }
        void display();
    };

}

// int Localclass :: z;
int main()
{

}
