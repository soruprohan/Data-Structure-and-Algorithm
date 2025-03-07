#include<iostream>
using namespace std;
class student;
class student
{
protected:
    int roll;
public:
    void set_roll(int roll){this->roll=roll;}
    void put_roll()
    {
        cout<<"Roll:"<<roll<<endl;
    }
};
class marks :virtual public student
{
protected:
    float sub1,sub2;
public:
    void set_marks(float s1,float s2)
    {
        this->sub1=s1;
        this->sub2=s2;
    }
    void put_marks()
    {
        cout<<"Marks of student "<<roll<<" in sub1="<<sub1<<",sub2="<<sub2<<endl;
    }
};

class sports : virtual public student
{
protected:
    float score;
public:
    void set_score(int s)
    {
        this->score=s;
    }
    void put_score()
    {
        cout<<"Score is "<<score<<endl;
    }
};
class result : public marks,public sports
{
protected:
    float result;
public:
   
    void display()
    {
        result=sub1+sub2+score;
        put_roll();
        put_marks();
        put_score();
        cout<<"Total marks is "<<result<<endl;
    }
};

int main()
{
    result ob;
    ob.set_roll(2107018);
    ob.set_marks(97,24.5);
    ob.set_score(90);
    ob.display();
}