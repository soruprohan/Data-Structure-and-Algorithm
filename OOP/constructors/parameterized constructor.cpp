#include<iostream>

using namespace std;

class test
{
    int m,n;
public:
    test (int,int);
    void display();
};

test :: test(int x,int y)
{
    m=x;
    n=y;
}
void test :: display()
{
    cout<<m<<"  "<<n<<endl;
}
int main()
{
    test aa=test(69,79); //explicit call;
    aa.display();
    aa=test(100,200); //re initialization using explicit call
    aa.display();

    test bb(50,55); //initializing using implicit call
    bb.display();
}
