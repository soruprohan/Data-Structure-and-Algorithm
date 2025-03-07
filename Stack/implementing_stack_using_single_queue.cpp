#include<iostream>
#include<queue>
using namespace std;

template<class T>
class Stack
{
    int s;
    queue<T> q1;
public:
    Stack():s(0){}

    void Push(T data)
    {
        q1.push(data);
        for(int i=0; i<q1.size()-1; i++){
            q1.push(q1.front());
            q1.pop();
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
