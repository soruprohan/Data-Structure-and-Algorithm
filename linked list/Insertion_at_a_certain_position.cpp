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

void add_at_pos(struct node *head,int data,int pos)
{
    struct node *temp=new struct node;
    temp->data=data;
    temp->link=NULL;

    struct node *ptr=head;

    for(int i=0; i<pos-1; i++){
        ptr=ptr->link;
    }
    temp->link=ptr->link;
    ptr->link=temp;
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
    struct node *temp=new struct node;
    temp->data=data;
    temp->link=head;

    head=temp;
    return head;
}

int main()
{
    struct node *head=new struct node;
    head->data=46;
    head->link=NULL;

    struct node *ptr=head;

    ptr=add_at_end(ptr,79);
    ptr=add_at_end(ptr,56);

    head=add_at_begin(head,54);

    add_at_pos(head,100,2);
    print_data(head);
}
