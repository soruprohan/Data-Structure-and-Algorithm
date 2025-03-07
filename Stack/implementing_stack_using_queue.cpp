#include<bits/stdc++.h>
using namespace std;

template<class T>
class Stack
{
    int s;
    queue<T> q1,q2;
public:
    Stack():s(0){}

    void Push(T data)
    {
        q2.push(data);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        s++;
    }

    void Pop()
    {
        q1.pop();
        s--;
    }

    T& Top()
    {
        return q1.front();
    }

    bool Empty()
    {
        return q1.empty();
    }

    int& Size()
    {
        return s; //or return q1.size()
    }

    void Print()
    {
        queue<T> temp=q1;
        while(!temp.empty()){
            cout<<temp.front()<<" ";
            temp.pop();
        }
        cout<<endl;
    }
};

int main()
{
    Stack<int> st;
    st.Push(10);
    st.Push(20);
    st.Push(30);
    st.Print();
    cout<<st.Size()<<endl;
    cout<<st.Top()<<endl;

    if(st.Empty()){
        cout<<"Stack is empty."<<endl;
    }
    else
        cout<<"Stack is not empty."<<endl;
    st.Pop();
    st.Print();

}
