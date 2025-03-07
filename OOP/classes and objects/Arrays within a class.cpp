#include<iostream>
#include<numeric>
using namespace std;

class marks
{
    int s[50];
    int sub;
    int sum;
public:
    void setdata();
    void display();
};

void marks :: setdata()
{
    int n;
    cout<<"Enter total subjects:";
    cin>>n;
    sub=n;
    for(int i=0; i<sub; i++){
        cin>>s[i];
    }
}
void marks :: display()
{
    cout<<"The marks are :"<<endl;
    for(int i=0; i<sub; i++){
        cout<<s[i]<<"\t";
    }
    cout<<endl;

    int sum=accumulate(s,s+sub,0);
    cout<<"The total mark is : "<<sum<<endl;
}
int main()
{
    marks aa;
    aa.setdata();
    aa.display();
}
