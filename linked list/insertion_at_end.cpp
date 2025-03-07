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
        cout<<"linked list is empty."<<endl;
    struct node *ptr=head;

    while(ptr!=NULL){
        cout<<ptr->data<<endl;
        ptr=ptr->link;
    }
}
void add_at_end(struct node *head,int data)
{
    struct node *ptr,*temp;
    ptr=head;

    temp=new struct node;
    temp->data=data;
    temp->link=NULL;

    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=temp;
}

int main()
{
    struct node *head=new struct node;
    head->data=45;
    head->link=NULL;

    struct node *current=new struct node;
    current->data=98;
    current->link=NULL;
    head->link=current;

    current=new struct node;
    current->data=67;
    current->link=NULL;
    head->link->link=current;

    add_at_end(head,69);
    print_data(head);
    return 0;
}



