#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *link;
};

void print_data(struct node *head)
{
    if(head==NULL)
        cout<<"Linked list is empty."<<endl;
    struct node *ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<endl;
        ptr=ptr->link;
    }
}

struct node* add_at_end(struct node *ptr,int data)
{
    struct node *temp=new struct node;
    temp->data=data;
    temp->link=NULL;

    ptr->link=temp;
    return temp;
}

int main()
{
    struct node *head=new struct node;
    head->data=45;
    head->link=NULL;

    struct node *ptr=head;

    ptr=add_at_end(ptr,98);
    ptr=add_at_end(ptr,3);
    ptr=add_at_end(ptr,69);

    print_data(head);
}
