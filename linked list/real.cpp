#include<iostream>
using namespace std;

template<class T>
struct node                         //Templatized struct
{
    T data;
    struct node* link;
};

template<class T>
class LinkedList
{
    struct node<T> *head;
public:
    LinkedList(void)               //default constructor
    {
        head=new struct node<T>;
        head->data=0;
        head->link=NULL;
    }

    LinkedList(T data)              //parameterized constructor
    {
        head=new struct node<T>;
        head->data=data;
        head->link=NULL;
    }

    ~LinkedList()                   //destructor for deallocating the memory
    {
        while(head!=NULL){
            struct node<T> *ptr=head;
            head=head->link;
            delete ptr;
        }
    }

    void insertFront(const T &value)        //Function to insert node in front of the linked list
    {
        struct node<T> *temp= new struct node<T>;
        temp->data=value;
        temp->link=head;

        head=temp;
    }

    void insertEnd(const T &value)         //Function to insert node in end of the linked list
    {
        struct node<T> *temp=new struct node<T>;
        temp->data=value;
        temp->link=NULL;

        struct node<T> *ptr=head;
        while(ptr->link!=NULL){
            ptr=ptr->link;
        }
        ptr->link=temp;
    }

    void insertAtPosition(int pos,const T &value)   //Function to insert node at a certain position of the linked list
    {
        if(pos<0){
            cout<<"Out of bound"<<endl;             //Shows out of bound if given position is negative
            return;
        }
        struct node<T> *temp=new struct node<T>;
        temp->data=value;
        temp->link=NULL;

        struct node<T> *ptr=head;
        for(int i=0; i<pos-1; i++){
            if(ptr==NULL){                           //Shows out of bound if given position is greater than the number of
                cout<<"Out of bound"<<endl;          //nodes available in the list.But this method will work for inserting node
                return;                              //at the end of the list i.e, at nth position
            }
            ptr=ptr->link;
        }
        temp->link=ptr->link;
        ptr->link=temp;
    }

    bool search(const T &value) const           //This function checks if an element exists in the list
    {
        struct node<T> *ptr=head;

        while(ptr!=NULL){
            if(ptr->data==value)
                return true;
            ptr=ptr->link;
        }
        return false;
    }

    void display() const                    //Traverses the whole list and prints nodes,shows a message if list is empty
    {
        if(head==NULL)
            cout<<"The list is empty."<<endl;
        else{
            struct node<T> *ptr=head;
            while(ptr!=NULL){
                cout<<ptr->data<<" ";
                ptr=ptr->link;
            }
            cout<<endl;
        }
    }

    int getLength() const               //Returns the number of nodes present in the list
    {
        int count=0;
        struct node<T> *ptr=head;
        while(ptr!=NULL){
            count++;
            ptr=ptr->link;
        }
        return count;
    }

};

int main()
{
    LinkedList<int> ob(10);
    ob.display();

    ob.insertEnd(20);
    ob.display();

    ob.insertFront(5);
    ob.display();

    ob.insertAtPosition(2,15);
    ob.display();

    cout<<ob.search(14)<<endl;
    cout<<ob.search(15)<<endl;

    cout<<ob.getLength()<<endl;
}
