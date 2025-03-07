#include<iostream>

using namespace std;

class name
{
    int id = 30;
    int age = 40;
public:
    void display()
    {
        cout << id << " " << age << endl;
    }


    name operator++(int)
    {
       name temp;
       temp.id=id;
       temp.age=age;

       id=id+1;
       age=age+1;

       return temp;
    }
     friend void operator++(name &ob)
    {
        ob.id=ob.id+1;
        ob.age=ob. age+1;
    }
};

int main()
{
    name ob, ob2;
     ob++;

    ob2.display();
    ++ob;
    ob.display();
}
