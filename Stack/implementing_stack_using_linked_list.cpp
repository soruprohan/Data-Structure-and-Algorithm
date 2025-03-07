#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node<T> *link;
};

template<class T>
class Stack
{
    struct node<T> *head;
    int s;
public:
    Stack()
    {
        head=NULL;
        s=0;
    }

    void Push(T data)
    {
        struct node<T> *temp=new struct node<T>;
        temp->data=data;
        temp->link=NULL;

        struct node<T> *ptr=head;
        if(head==NULL){
            head=temp;
        }
        else{
            temp->link=head;
            head=temp;
        }
        s++;
    }

    void Pop()
    {
        struct node<T> *temp=head;
        head=head->link;
        delete temp;
        s--;
    }

    bool Empty()
    {
        if(s==0)
            return true;
        return false;
    }

    T& Top()
    {
        return head->data;
    }

    int Size()
    {
        return s;
    }

    void Print()
    {
        struct node<T> *ptr=head;
        while(ptr!=NULL){
            cout<<ptr->data<<" ";
            ptr=ptr->link;
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
