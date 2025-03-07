#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    ofstream fout("ITEM");
    cout<<"Enter item name:";
                                 //Alternative method:
    char name[30];               //string name;
    cin.getline(name,30);        //getline(cin,name);   
    
    fout<<name<<endl;

    cout<<"Enter item cost:";
    float cost;
    cin>>cost;
    fout<<cost<<endl;

    fout.close();

    ifstream fin("ITEM");

    strcpy(name,"rohan"); //this is the proof that  name and cost is not getting read from console,but from file
    cost=100;  
     
    fin.getline(name,30);             //ALternative method,if i had used string instead of char array:
    fin>>cost;                        //getline(fin,name);   
                        
                                    
    cout<<"From file ,name:"<<name<<endl;
    cout<<"From file,price:"<<cost<<endl;

    fin.close();

}