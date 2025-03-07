#include<iostream>
#include<string>
using namespace std;

class show
{
    string name;
    int age;
    float cg;
public:
    friend istream& operator>>(istream &, show&);
    friend ostream& operator<<(ostream& COUT,show &ob);
};

istream& operator>>(istream& CIN,show &ob)
{
    cout<<"Name:";
    CIN>>ob.name;
    cout<<"age:";
    CIN>>ob.age;
    cout<<"cg:";
    CIN>>ob.cg;

    return CIN;
}
ostream& operator<<(ostream& COUT,show &ob)
    {
        COUT<<ob.name<<endl;
        COUT<<ob.age<<" "<<ob.cg<<endl;
        return COUT;
    }
int main()
{
    show ob,ob2;
    cin>>ob>>ob2;
    cout<<ob<<endl;
    cout<<ob2<<endl;
}
