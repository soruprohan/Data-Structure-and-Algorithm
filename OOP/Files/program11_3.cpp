#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;
int main()
{
    ifstream fin1,fin2;
    fin1.open("country");
    fin2.open("capital.txt");

    char line[50];

    for(int i=0; i<10; i++)
    {
    if(fin1.eof()!=0)
        {
            cout<<"Exit from country"<<endl;
            exit(0);
        }
        fin1.getline(line,50);
        cout<<line<<endl;

        if(fin2.eof()!=0)
        {
            cout<<"Exit from capital"<<endl;
            exit(0);
        }
        fin2.getline(line,50);
        cout<<line<<endl;
    }
    
}
