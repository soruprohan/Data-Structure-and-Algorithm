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

    friend name operator+( name ob, name ob2)
    {
        name ob3;
        ob3.id = ob.id + ob2.id;
        ob3.age = ob.age + ob2.age;
        return ob3;
    }

};

int main()
{
    name ob, ob2, ob3, ob4;

    ob4 = ob + ob2;
    ob4.display();
    ob4 = ob + ob2 +ob3;
    ob4.display();

}
