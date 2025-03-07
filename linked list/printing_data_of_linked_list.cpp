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

    print_data(head);
    return 0;
}


