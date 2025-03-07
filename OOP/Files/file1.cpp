#include<fstream>
#include<iostream>
using namespace std;

template< class T>
class test
{
    T a;
public:
    test(){cout<<"Default constructor"<<endl;}
    test(T a):a(a){cout<<"Parameterized constructor"<<endl;}

    T get_a();

    ~test(){cout<<"Destructor called"<<endl;}

    void display();

    template<class I>
    friend istream& operator>>(istream& CIN, test<I> &ob);

    template<class O>
    friend ostream& operator<<(ostream& COUT,test<O> &ob);
};

template<class T>
void test<T>:: display()
{
    cout<<"a is "<<a<<endl;
}

template<class T>
T test<T>:: get_a()
{
    return a;
}

template<class I>
istream& operator>>(istream& CIN, test<I> &ob)
{
    CIN>>ob.a;
    return CIN;
}

template<class T>
ostream& operator<<(ostream& COUT,test<T> &ob)
{
    COUT<<"a is "<<ob.a;
    return COUT;
}

int main()
{
    ofstream fout;
    fout.open("file1.txt");

    test<float> ob1,ob2;

    ob1=test<float>(4.5);

    cout<<"Enter object:";
    cin>>ob2;

    test<float>ob3(5.5);

    fout<<ob1<<endl;
    fout<<ob2<<endl;
    fout<<ob3<<endl;

    fout.close();

    ifstream fin;
    fin.open("file1.txt");
    string cline;

    while(!fin.eof())
    {
        getline(fin,cline);
        cout<<cline<<endl;
    }
}
