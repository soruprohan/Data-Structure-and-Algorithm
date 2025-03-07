#include<iostream>
using namespace std;

class student
{
protected:
    int roll;
public:
    student()
    {
         cout<<"Student constructor called"<<endl;
    }
    student(int roll) : roll(roll)
    {
        cout<<"Student constructor called"<<endl;
    }
    void put_roll()
    {
        cout<<"Roll is "<<roll<<endl;
    }
};
class marks : public student
{
protected:
    float sub1,sub2;
public:
    marks(){}
    marks(float sub1,float sub2)
    {
        this->sub1=sub1;
        this->sub2=sub2;
        cout<<"class marks constructed"<<endl;
    }
    void put_marks()
    {
        cout<<"Marks of student in sub1="<<sub1<<",sub2="<<sub2<<endl;
    }
};

class sports :virtual public student
{
protected:
    float score;
public:
    sports(){}
    sports(float score)
    {
        this->score=score;
        cout<<"class sports constructed"<<endl;
    }
    void put_score()
    {
        cout<<"Score is "<<score<<endl;
    }
};

class result : public marks, public sports
{
protected:
    float total,cash;
public:
    result(){}
    result(int roll,float sub1,float sub2,float score,float cash) :
          marks(sub1,sub2),sports(score)
          {
            this->cash=cash;
            cout<<"class result constructed"<<endl;
          }
   
    void display()
    {
        total=sub1+sub2+score;
       
       // put_roll();
        put_marks();
        put_score();
        cout<<"Total marks is "<<total<<endl;
        cout<<"Total money he has: "<<cash<<endl;
    }
};

int main()
{
    result ob(2107018,18,19.5,29.8,12000.45);
    //ob.display();
}