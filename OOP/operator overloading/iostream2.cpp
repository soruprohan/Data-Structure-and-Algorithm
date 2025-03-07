#include<iostream>
#include<string>
using namespace std;

class show
{
    string name;
    int age;
    float cg;
public:
    friend istream& operator>>(istream &, show &);
    ostream& operator<<(ostream& COUT)
    {
        COUT<<name<<endl;
        COUT<<age<<" "<<cg<<endl;
        return COUT;
    }
};

istream & operator>>(istream& CIN,show &ob)
{
    cout<<"Name:";
    CIN>>ob.name;
    cout<<"age:";
    CIN>>ob.age;
    cout<<"cg:";
    CIN>>ob.cg;

    return CIN;
}

int main()
{
    show ob,ob2;
    cin>>ob>>ob2;

    cout<<ob2<<endl;
}

