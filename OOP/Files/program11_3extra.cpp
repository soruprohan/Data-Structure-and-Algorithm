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

    while(!fin1.eof() || !fin2.eof())
    {
      
        fin1.getline(line,50);
        cout<<line<<endl;

        fin2.getline(line,50);
        cout<<line<<endl;
    }
    
}
