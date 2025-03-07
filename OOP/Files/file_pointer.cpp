#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

int main()
{
    fstream foutfin;
    foutfin.open("input",ios::out|ios::in);
    char str[100];
    cout<<"Enter a string:";
    cin.getline(str,100);

    int len=strlen(str);

    

    for(int i=0; i<len; i++){
        foutfin.put(str[i]);
    }
    foutfin.seekg(0);

    char ch;
    while(foutfin)
    {
        foutfin.get(ch);
        cout<<ch;
    }
    foutfin.close();
}