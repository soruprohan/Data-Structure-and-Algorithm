#include<iostream>
using namespace std;
#define INF ULONG_MAX

double getAbsolute(double i)
{
    return i>=0 ? i:-i;
}

double divide(double x,double y)
{
    int sign=1;
    if(x*y<0)
        sign=-1;

    double precision=0.001;

    x=getAbsolute(x);
    y=getAbsolute(y);
    double low=0,high=INF;

    while(1){
        double mid=low+(high-low)/2;

        if(getAbsolute(y*mid-x)<=precision)
            return mid*sign;
        if(y*mid >x)
            high=mid;
        else
            low=mid;
    }
}
int main()
{
    double x,y;
    cin>>x>>y;

    cout<<divide(x,y)<<endl;
}
