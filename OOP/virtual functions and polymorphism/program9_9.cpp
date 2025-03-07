#include<iostream>
#include<cstring>
using namespace std;

class A
{
    char *str;
    int len;
    public:
    void set_data()
    {
        char *s=new char[40];
        cout<<"Enter string:";
        cin>>s;

        len=strlen(s);

        str=new char[len+1];
        strcpy(str,s);
    }
    void show()
    {
        cout<<"str is="<<str<<endl;
    }

};

int main()
{
    A *ob[10];
    int i=0;
    int key;
    do{
        ob[i]=new A;
        ob[i]->set_data();
        i++;
        cout<<"Press 0 to exit and any key to store more."<<endl;
        cin>>key;
        cin.ignore();
    }while(key);

    int j=0;
    while(i--)
    {
        ob[j]->show();
        j++;
    }
        
}