#include<iostream>
#include<stack>
using namespace std;

template<class T>
class Queue
{
    stack<T> st1,st2;
    int s;
public:
    Queue(){s=0;}

    void Push(T data)
    {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        st2.push(data);
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        s++;
    }
    void Pop()
    {
        st1.pop();
        s--;
    }

    T& Front()
    {
        return st1.top();
    }

    bool Empty()
    {
        if(s==0)
            return true;
        return false;
    }

    int& Size()
    {
        return s;
    }

    void Print()
    {
        stack <T> temp=st1;
        while(!temp.empty()){
            cout<<temp.top()<<" ";
            temp.pop();
        }
        cout<<endl;
    }
};

int main()
{
    Queue<int> q;
    q.Push(10);
    q.Push(20);
    q.Push(30);
    q.Print();
    cout<<q.Size()<<endl;
    cout<<q.Front()<<endl;

    if(q.Empty()){
        cout<<"Queue is empty."<<endl;
    }
    else
        cout<<"Queue is not empty."<<endl;
    q.Pop();
    q.Print();

}
