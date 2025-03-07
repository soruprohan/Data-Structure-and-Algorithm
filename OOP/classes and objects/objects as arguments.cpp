#include<iostream>

using namespace std;
class time
{
    int hour;
    int minute;
public:
    void getdata(int,int);
    void showdata(void);
    void sum(time,time);
};

void time :: getdata(int hour,int minute)
{
    this-> hour=hour;
    this->minute=minute;
}
void time :: showdata(void)
{
    cout<<hour<<" hours "<<minute<<" minutes "<<endl;
}
void time :: sum(time t1,time t2)
{
    int m=t1.minute+t2.minute;
    int h=m/60;                 //here h and m are local variables

    minute=m%60;               //here miniute and hour t3 er,karon ei function ta t3 object diye call kora hoise
    hour=h+t1.hour+t2.hour;
}

int main()
{
    time t1,t2,t3;
    int h1,h2,m1,m2;

    cout<<"Enter hours:"<<endl;
    cin>>h1>>h2;
    cout<<"Enter minutes:"<<endl;
    cin>>m1>>m2;

    t1.getdata(h1,m1);
    t2.getdata(h2,m2);

    t3.sum(t1,t2);

    t1.showdata();
    t2.showdata();
    cout<<"After adding "<<endl;
    t3.showdata();
}
