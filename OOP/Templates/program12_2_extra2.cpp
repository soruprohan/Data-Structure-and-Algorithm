#include<iostream>
using namespace std;

template<class T>
class Vector
{
    T *v;
    int size;
public:
    Vector(){}
    Vector(int n):size(n)
    {
        v=new T[size];
        for(int i=0; i<size; i++){
            v[i]=0;
        }
    }
    Vector(int n,T elem):size(n)
    {
        v=new T[size];
        for(int i=0; i<size; i++){
            v[i]=elem;
        }
    }
    Vector(int n,T *arr):size(n)
    {
        v=new T[size];
        for(int i=0; i<size; i++){
            v[i]=arr[i];
        }
    }
    ~Vector(){
        delete[] v;
    }

    void operator*(Vector<T> ob){
    for(int i=0; i<ob.size; i++)
        v[i]=v[i]*ob.v[i];
    }

    template<class V>
    friend ostream& operator<<(ostream&COUT ,Vector<V> &ob);

    template<class U>
    friend  Vector<U> operator=(Vector<U> &ob1,Vector<U> &ob2);
};

template<class V>
ostream& operator<<(ostream&COUT ,Vector<V> &ob)
{
    cout<<ob.size<<endl;
    for(int i=0; i<ob.size; i++){
        cout<<ob.v[i]<<" ";
    }
    return COUT;
}


int main()
{
    Vector<int> vec(3,5);
    Vector<int>vec2(5,1);
    cout<<vec<<endl;
    cout<<vec2<<endl;
    
    Vector<int>vec3;
}