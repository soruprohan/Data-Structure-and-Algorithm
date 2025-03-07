#include<iostream>
using namespace std;

class item
{
    static int countt;
    int number;
public:
    void getdata(int);
    void display(void);
};
int item :: countt;

void item :: getdata(int a)
{
    number=a;
    countt++;
    display();
}
void item :: display()
{
    cout<<"Number is "<<number<<endl;
    cout<<"Count is "<<countt<<endl;
}
int main()
{
    int a,b,c;
    cout<<"Enter three numbers:"<<endl;
    cin>>a>>b>>c;
    item aa,bb,cc;
    aa.getdata(a);
    bb.getdata(b);
    cc.getdata(c);

}
