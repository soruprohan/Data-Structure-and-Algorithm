#include<iostream>
#include<string>

using namespace std;

class employee
{
    string name;
    int age;
    float salary;
public:
    void getdata();
    void showdata();
};
void employee :: getdata()
{
    cout<<"Name:";
    getline(cin,name);
    cout<<"Age:";
    cin>> age;
    cin.ignore();
    cout<<endl;
}
void employee :: showdata()
{
    cout<<"Name is "<<name<<endl;
    cout<<"Age is "<<age<<endl;
}

int main()
{
    employee manager[3];
    employee senior[10];
    employee junior[50];

    int n1,n2,n3;

    cout<<"Enter how many managers you want to save:"<<endl;
    cin>>n1;
    cin.ignore();
    cout<<"Enter manager details"<<endl;
    for(int i=0; i<n1; i++){
        manager[i].getdata();
    }

    cout<<"Enter how many seniors you want to save:"<<endl;
    cin>>n2;
    cin.ignore();
    cout<<"Enter senior details"<<endl;
     for(int i=0; i<n2; i++){
        senior[i].getdata();
    }

    cout<<"Enter how many juniors you want to save:"<<endl;
    cin>>n3;
    cin.ignore();
    cout<<"Enter junior details"<<endl;
     for(int i=0; i<n3; i++){
        junior[i].getdata();
    }


     for(int i=0; i<n1; i++){
        cout<<"manager "<<i+1<<":"<<endl;
        manager[i].showdata();
    }
     for(int i=0; i<n2; i++){
         cout<<"senior "<<i+1<<":"<<endl;
         senior[i].showdata();
    }
     for(int i=0; i<n3; i++){
        cout<<"junior "<<i+1<<":"<<endl;
        junior[i].showdata();
    }
}
