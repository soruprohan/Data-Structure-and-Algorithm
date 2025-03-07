#include<iostream>
using namespace std;

template<class T,class V>
class mypair
{
    T k;
    V v;
public:
    mypair(){}
    mypair(T k, V v):k(k),v(v){}

    void display()
    {
        cout<<k<<":"<<v<<endl;
    }
};

template<class T>
class Vector
{
    int size;
    T arr[1000];
public:
    Vector()
    {
        size=0;
    }
    void pushback(T data)
    {
        arr[size]=data;
        size++;
    }
    T get(int i)
    {
        return arr[i];
    }
    T operator[](int position)
    {
        return arr[position];
    }
};

int main()
{
    mypair<string,int> mp("abcde",10);
    Vector<mypair<string,int>>vec;

    vec.pushback(mp);
    vec.get(0).display();
    vec[0].display();
}