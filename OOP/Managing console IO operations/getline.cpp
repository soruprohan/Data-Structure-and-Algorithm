#include<iostream>
#include<string>
using namespace std;

int main()
{
    char str[40];
    string name;
    cin.getline(str,20);

    getline(cin,name);

    cout<<str<<endl;
    cout<<name<<endl;
}