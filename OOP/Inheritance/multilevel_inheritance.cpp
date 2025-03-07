#include<iostream>
using namespace std;

class student
{
protected:
    int roll;
public:
    void set_roll(int roll){ this ->roll=roll; }
    void put_roll(void)
    {
        cout<<"Roll of the student: "<<roll<<endl;
    }
};
class test :public student
{
protected:
    float sub1,sub2;
public:
    void set_marks(float sub1,float sub2)
    {
        this->sub1=sub1;
        this->sub2=sub2;
    }
    void put_marks()
    {
        cout<<"sub1:"<<sub1<<endl
            <<"sub2:"<<sub2<<endl;
    }
};
class result :public test
{
    float total;
public:
    void display()
    {   
        total=sub1+sub2;
        put_roll();
        put_marks();
        cout<<"Total marks is: "<<total<<endl;
    }
};

int main()
{
    result stu;
    stu.set_roll(2107018);
    stu.set_marks(87.5,92.5);

    stu.put_marks();
    cout<<endl;
    stu.display();
}