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
struct node* add_at_begin(struct node *head,int data)
{
    struct node *ptr=new struct node;
    ptr->data=data;
    ptr->link=head;

    head=ptr;
    return head;
}

int main()
{
    struct node *head=new struct node;
    head->data=67;
    head->link=NULL;

    struct node *ptr=head;

    ptr=add_at_end(ptr,56);
    ptr=add_at_end(ptr,46);

    head=add_at_begin(head,47);

    print_data(head);
}
