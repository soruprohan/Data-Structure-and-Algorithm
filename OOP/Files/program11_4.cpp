#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

int main()
{
    fstream foutfin;
    foutfin.open("input",ios::out|ios::in); //for this operation to happen the file must exist beforehand,it will not create a new input file

    char str[100];
    cout<<"Enter a string:";
    cin.getline(str,100);

    int len=strlen(str);

    
    int i=0;
    while(i<len){
        foutfin.put(str[i]);
        i++;
    }
    foutfin.seekg(0);

    char ch;
    while(!foutfin.eof())
    {
        foutfin.get(ch);
        cout<<ch;
    }
    foutfin.close();
}