#include<iostream>
using namespace std;

class num
{
    int m,n;
public:
    void getdata();
    void putdata();
    int largest();
};

void num :: getdata()
{
    cout<<"Enter two numbers:"<<endl;
    cin>>m>>n;
}
int num :: largest()
{
    if(m>=n)
        return m;
    else
        return n;
}
void num :: putdata(void)
{
    cout<<"The numbers are "<<m<<" and "<<n<<"."<<endl;
    cout<<"And the largest number is "<<largest()<<"."<<endl;
}
int main()
{
    num aa;
    aa.getdata();
    aa.putdata();
}
