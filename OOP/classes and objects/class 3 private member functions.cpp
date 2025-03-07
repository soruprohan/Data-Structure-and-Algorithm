#include<iostream>
using namespace std;

class num
{
    int bal;
    int age;
    void putdata(void);
public:
    void getdata(void);
};

void num :: getdata(void)
{
    cout<<"Enter balance and age:"<<endl;
    cin>>bal>>age;
    putdata();
}

void num :: putdata(void)
{
    cout<<"The outputs are "<<bal<<" and "<<age<<"."<<endl;
    cout<<"And the multiplication is "<<bal*age<<"."<<endl;
}
int main()
{
    num aa;
    aa.getdata();

}


