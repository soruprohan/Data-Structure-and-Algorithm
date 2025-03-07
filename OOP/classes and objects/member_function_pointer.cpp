#include<iostream>

using namespace std;
 
class Member
{
    int x,y;
public:
    void setdata(int x,int y)
    {
        this->x=x;
        this->y=y;
    }
    friend int sum(Member ob);
   
};
int sum(Member ob)
 {
        int (Member:: *px)=& Member::x;
        int Member:: *py=& Member::y;
        Member *pM=&ob;

        int s;
        s=pM->*px +ob.*py;
        return s;
}   


int main()
{
    void (Member :: *setdata_ptr)(int,int)= &Member :: setdata;

    Member ob;
    (ob.*setdata_ptr)(100,20);

    int (*sum_ptr)(Member)=&sum;

    cout<<(*sum_ptr)(ob)<<endl;

}
