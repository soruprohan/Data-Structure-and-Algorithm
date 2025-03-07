#include<iostream>
using namespace std;
class test
{
    static int countt;
    int code;
public:
    void setcode(void);
    void showcode(void);
    static void showcount(void); //ei code ta static member function er bodole normal member function diyeo kora jay,output eki asbe,next code e kora hoise ota
};


void test :: setcode()
{
    code=++countt;
}
void test :: showcode(void)
{
    cout<<"Object number: "<<code<<endl;
}
 void test :: showcount()
{
    cout<<"Count is "<<countt<<endl;
    }

int test :: countt;

int main()
{
    test aa,bb;
    aa.setcode();
    bb.setcode();

    test :: showcount(); // normal member function diye korte chaile ekhane aa.showcount() or bb.showcount() or cc.showcount() dilei hoito,eki output ashto
                         // karon count ke show korar jonno jei object e use kori na ken count to static,memory location ektai
    aa.showcode();
    bb.showcode();

    test cc;
    cc.setcode();

    test :: showcount();
}
