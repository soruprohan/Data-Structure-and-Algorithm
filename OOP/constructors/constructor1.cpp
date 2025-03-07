#include<iostream>
using namespace std;

class test
{
    int m,n;
public:
    test(void);
    void display();
};

test :: test(void)
{

}
void test :: display()
{
    cout<<m<<"\t"<<n<<endl;
}
int main()
{
    test aa;
    aa.display();
}
