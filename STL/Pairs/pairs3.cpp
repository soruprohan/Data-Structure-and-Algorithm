#include<bits/stdc++.h>
using namespace std;

int main()
{
    pair<string,double> p,p2,&p1=p;

    cin>>p.first>>p.second;

    cout<<p.first<<" "<<p.second<<endl;



    p1={"karim",3.82};
    p2={"rahim",3.84};
    cout<<p1.first<<" "<<p1.second<<endl;
    cout<<p.first<<" "<<p.second<<endl;
    cout<<p2.first<<" "<<p2.second<<endl;
}
