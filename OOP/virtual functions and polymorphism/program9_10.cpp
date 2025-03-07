#include<iostream>
#include<cstring>
#include<string>

using namespace std;

class A
{
    char *name;
    int age;
    public:
    void set_data()
    {
        char *str=new char[50];
        cout<<"Enter name:";
        gets(str);

        name=new char[50];
        strcpy(name,str);

        cout<<"Enter age:";
        cin>>age;
        cin.ignore();
    }
    A compare(A ob)
    {
        if(age>ob.age)
        {
            return *this;
        }
        else 
            return ob;
    }
    void show()
    {
        cout<<"Name="<<name<<endl;
        cout<<"Age="<<age<<endl;
    }
};
int main()
{
    A ob;
    A *ptr=&ob;
    ptr->set_data();
    
    A *ptr2=new A;
    ptr2->set_data();

    A ob2=ptr->compare(*ptr2);

    ptr->show();
    ptr2->show();

    cout<<"Elder person is :"<<endl;
    ob2.show();

    delete ptr2; 
}