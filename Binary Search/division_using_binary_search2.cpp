#include<iostream>
using namespace std;
#define INF ULONG_MAX

double getAbsolute(double i)
{
    return i>=0 ? i : -i;
}

double divide(double x,double y)
{
    if(y==0)
        return INF;
    double precision=0.001;

    int sign=1;
    if(x*y<0)
        sign=-1;

    x=getAbsolute(x);
    y=getAbsolute(y);

    double start=0,end=INF;
    while(1){
       double mid=start+(end-start)/2;

       if(getAbsolute(mid*y-x)<=precision)
            return mid*sign;
       if(y*mid<x)
            start=mid;
       else
            end=mid;
    }
}

int main()
{
    double x,y;
    cin>>x>>y;

    cout<<divide(x,y)<<endl;
}
