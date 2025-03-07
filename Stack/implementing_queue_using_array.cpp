#include<iostream>
using namespace std;

const int N=100;

template<class T>
class Queue
{
    T arr[N];
    int s=0;
public:
    void push(T value)
    {
        arr[s++]=value;
    }
    void pop()
    {
        for(int i=0; i<s; i++){
            arr[i]=arr[i+1];
        }
        s--;
    }
    T& top()
    {
        return arr[0];
    }
    bool Empty()
    {
        if(s!=0)
            return false;
        return true;
    }
    int Size()
    {
        return s;
    }

    template<class U>
    friend void print(Queue<U> );

};

    template<class U>
    void print(Queue<U> q)
    {
        for(int i=0; i<q.s; i++){
            cout<<q.arr[i]<<" ";
        }
        cout<<endl;
    }

int main()
{
    Queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    print(q);
    cout<<q.top()<<endl;
    q.pop();
    print(q);
    cout<<q.Size()<<endl;
    if(q.Empty())
        cout<<"The stack is empty"<<endl;
    else
        cout<<"The stack is not empty"<<endl;

}

