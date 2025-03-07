#include<iostream>
#include<fstream>

//file er khetre char [] neya bad,string niba only,condition checking er khetre while(fin) bad 
//while(!fin.eof()) niba only,egula korle jemon chao temon ans paba,no unexpected results

using namespace std;

int main()
{
    ofstream fout;
    fout.open("country");

    fout<<"United states of america"<<endl;
    fout<<"United kingdom";

    fout.close();
    fout.open("capital.txt");

    fout<<"Washington DC"<<endl;
    fout<<"LOndon";

    fout.close();

    ifstream fin;
    fin.open("country");

    string cline;

    while(!fin.eof())
    {
        getline(fin,cline);
        cout<<cline<<endl;
    }
    fin.close();

    fin.open("capital.txt");

    string sline;
    while(!fin.eof())
    {
        getline(fin,sline);
        cout<<sline<<endl;
    }
    fin.close();
}