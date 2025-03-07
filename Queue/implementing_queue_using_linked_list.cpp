#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node<T> *link;
};

template<class T>
class Queue
{
    struct node<T> *head;
    int s;
public:
    Queue()
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
            while(ptr->link!=NULL){
                 ptr=ptr->link;
            }
            ptr->link=temp;
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

    T& Front()
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
