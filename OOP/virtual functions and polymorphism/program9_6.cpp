#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
    char str[]="c++ is better than c";
    int len1=strlen(str);
    char *ptr=new char[len1];
    cin>>ptr;

    int len2=strlen(ptr);

    int i=0;
    for(; i<len1; i++)
    {
        int k=i;
        for(int j=0; j<len2; j++)
        {
             if(str[k]==ptr[j])
             {
                if(j==len2-1)
                    cout<<"Substring is available."<<endl;

                k++;
             }
             else 
                break;
        }     
    }
    if(i==len1)
        cout<<"The substring is not present"<<endl;
        delete [] ptr;

}