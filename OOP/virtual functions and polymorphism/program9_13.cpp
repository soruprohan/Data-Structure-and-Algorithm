#include<iostream>
#include<cstring>
using namespace std;

class media
{
    protected:
        char title[50];
        float price;
    public:
        media(char *s,float price):price(price)
        {
            strcpy(title,s);
        }
        virtual void display()=0;
};

class book: public media
{
    int page;
    public:
        book(char *s,float price,int page):media(s,price),page(page)
        {

        }
    void display()
    {
        cout<<"Title:"<<title<<endl;
        cout<<"Price:"<<price<<endl;
        cout<<"Pages:"<<page<<endl;
    }
};

class tape: public media
{
    float playTime;
    public:
        tape(char *s,float price,float playTime):media(s,price),playTime(playTime)
        {

        }
    void display()
    {
        cout<<"Title:"<<title<<endl;
        cout<<"Price:"<<price<<endl;
        cout<<"Play time:(mins)"<<playTime<<endl;
    }
};

int main()
{
    book book1("balaguru",230.50,400);
    tape tape1("Herbart",430.50,300);

    media *ptr[2];
    ptr[0]=&book1;
    ptr[1]=&tape1;

    ptr[0]->display();
    ptr[1]->display();
}