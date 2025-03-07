#include<iostream>

using namespace std;

class test
{
    int id;
public:
    test(){};
    test(int id)
    {
        this -> id=id;
    };
    test(const test &ob) //always copy constructor er samne const keyword use korba,taile konoprokar error ashbe na
    {
        this ->id=ob.id;
    }

    friend void show(test &ob);
};

void show(test &ob)
{
    cout<<"ID:"<<ob.id<<endl;
}
int main()
{
    //test ob2(1235);   //implicit call of parameterized constructor

    test ob2=test(1235);//explicit call of parameterized constructor
    test ob3(ob2); //implicit call of copy constructor

    show(ob2);
    show(ob3);
}
