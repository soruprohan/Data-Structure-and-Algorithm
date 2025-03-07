#include<iostream>
using namespace std;

template<class T>
class Vector
{
    T *a;
    int size;
public:
    Vector(){}
    Vector(int size):size(size)
    { 
      a=new T[size];
    }
    ~Vector(){ delete[] a;}
    
    template<class A>
    friend istream& operator>>(istream &CIN , Vector<A> &ob);
    template<class B>
    friend ostream& operator<<(ostream &COUT , Vector<B> &ob);
    T& operator[](int index);
};

template<class T>
istream& operator>>(istream &CIN , Vector<T> &ob)
{
    for(int i=0; i<ob.size; i++){
        CIN>>ob.a[i];
    }
    return CIN;
}

// template<class T>
// ostream& operator<<(ostream &COUT, Vector<T> &ob)
// {
//     COUT<<ob.size<<endl;
//     for(int i=0; i<ob.size; i++){
//         COUT<<ob.a[i]<<" ";
//     }
//     return COUT;
// }

template<class T>
T& Vector<T>:: operator[](int index)
{
    return a[index];
}

int main()
{
    Vector<int> vec(3);
    cin>>vec;
    vec[1]=90;
    cout<<vec[0]<<vec[1]<<vec[2];
}