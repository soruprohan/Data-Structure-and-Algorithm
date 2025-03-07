#include<iostream>
using namespace std;

class student
{
protected:
    int roll;
public:
    student()
    {
         cout<<"Student"<<endl;
    }
    student(int roll) : roll(roll)
    {
        cout<<"Student"<<endl;
    }
    void put_roll()
    {
        cout<<"Roll is "<<roll<<endl;
    }
};
class marks :virtual public student
{
protected:
    float sub1,sub2;
public:
    marks(){}
    marks(float sub1,float sub2)
    {
        this->sub1=sub1;
        this->sub2=sub2;
        cout<<"marks"<<endl;
    }
    void put_marks()
    {
        cout<<"Marks of student in sub1="<<sub1<<",sub2="<<sub2<<endl;
    }
};

class sports : public student
{
protected:
    float score;
public:
    sports(){}
    sports(float score)
    {
        this->score=score;
        cout<<"sports"<<endl;
    }
    void put_score()
    {
        cout<<"Score is "<<score<<endl;
    }
};

class dummy :virtual public student
{
protected:
    float dub1,dub2;
public:
    dummy(){}
    dummy(float dub1,float dub2)
    {
        this->dub1=dub1;
        this->dub2=dub2;
        cout<<"dummy"<<endl;
    }
    void put_dummy()
    {
        cout<<"Marks of student in sub1="<<dub1<<",sub2="<<dub2<<endl;
    }
};

class lummy : public student
{
protected:
    float lub1,lub2;
public:
    lummy(){}
    lummy(float lub1,float lub2)
    {
        this->lub1=lub1;
        this->lub2=lub2;
        cout<<"lummy"<<endl;
    }
    void put_lummy()
    {
        cout<<"Marks of student in sub1="<<lub1<<",sub2="<<lub2<<endl;
    }
};

class result : public marks, virtual public sports,virtual public dummy,public lummy
{
protected:
    float total,cash;
public:
    result(){}
    result(int roll,float sub1,float sub2,float score,float cash,float dub1, float dub2, float lub1, float lub2) :
          marks(sub1,sub2),sports(score),dummy(dub1,dub2),lummy(lub1,lub2)
          {
            this->cash=cash;
            cout<<"result"<<endl;
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
    result ob(2107018,18,19.5,29.8,12000.45,4.3,2.3,4.9,1.2);
   // ob.display();
}