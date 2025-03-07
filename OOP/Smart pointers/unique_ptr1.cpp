#include<memory>
#include<iostream>
using namespace std;

class Test
{
    private:
    int data;
    public:
    Test():data(0){
        cout<<"Deefault con"<<endl;
    }
    Test(int data):data(data)
    {
        cout<<"Paramterized con"<<endl;
    }
    ~Test()
    {
        cout<<"Test destructor"<<endl;
    }
    void display()
    {
        cout<<data<<endl;
    }

};

int main()
{
    Test *t1=new Test(100);
    delete t1;

    unique_ptr<Test> t2= make_unique<Test>(1000);
    t2->display();

    unique_ptr<Test> t3{new Test(200)};
    t3=move(t2);

    t3->display();

    if(!t2)
    cout<<"T2 is null now"<<endl;
}