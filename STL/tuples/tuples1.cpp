#include<bits/stdc++.h>
#include<tuple>
using namespace std;

int main()
{
    tuple<int,char,float> t,t1(10,'a',3.4);
    t=make_tuple(20,'b',6.8);

    cout<<get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<endl;
    cout<<get<0>(t1)<<" "<<get<1>(t1)<<" "<<get<2>(t1)<<endl;
    swap(t,t1);
    cout<<get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<endl;
    cout<<get<0>(t1)<<" "<<get<1>(t1)<<" "<<get<2>(t1)<<endl;

    cout<<tuple_size<decltype(t)>::value <<endl;
    cout<<tuple_size<tuple<int,char,float>>::value <<endl;

    int a;
    char b;
    float c;

    tie(a,b,c)=t;

    cout<<a<< " "<<b<<" "<<c<<" "<<endl;

    auto t2 =tuple_cat(t,t1);
    cout<<get<0>(t2)<<" "<<get<1>(t2)<<" "<<get<2>(t2)<<" "
        <<get<3>(t2)<<" "<<get<4>(t2)<<" "<<get<5>(t2)<<endl;
}
