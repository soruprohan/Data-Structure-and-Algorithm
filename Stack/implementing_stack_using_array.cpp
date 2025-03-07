#include<iostream>
using namespace std;

const int N=100;

template<class T>
class Stack
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
        s--;
    }
    T& top()
    {
        return arr[s-1];
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
    friend void print(Stack<U> );

};

    template<class U>
    void print(Stack<U> st)
    {
        for(int i=0; i<st.s; i++){
            cout<<st.arr[i]<<" ";
        }
        cout<<endl;
    }

int main()
{
    Stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    print(st);
    cout<<st.top()<<endl;
    st.pop();
    //st.print();
    cout<<st.Size()<<endl;
    if(st.Empty())
        cout<<"The stack is empty"<<endl;
    else
        cout<<"The stack is not empty"<<endl;

}
