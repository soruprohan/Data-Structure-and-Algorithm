#include<iostream>
using namespace std;

template<class T>
void swap_(T &a, T &b) //only swap likhle built in swap() function er sathe ambiguity toiri hoy,error dey
{
    T temp;
    temp=a;
    a=b;
    b=temp;
}

int main()
{
    char a,b;
    cout<<"Enter a & b:";
    cin>>a>>b;

    float c,d;
    cout<<"Enter c & d:";
    cin>>c>>d;

    swap_<char>(a,b);
    swap_<float>(c,d); //bracket er majhe <float> emne na likhe normal function call dileo kaj korbe,but bracket er majhe vul
                        //data type dile kaj korbe na,jemon data jodi float er nei c and d er ar ami bracket er majhe
                        //char dei taile error dibe
    
    cout<<"a="<<a<<" "<<"b="<<b<<endl;

    cout<<"c="<<c<<" "<<"d="<<d<<endl;
}
