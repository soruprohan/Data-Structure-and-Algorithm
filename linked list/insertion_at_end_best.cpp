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

struct node* add_at_begin(struct node *head,int data)
{
    struct node *temp=new struct node;
    temp->data=data;
    temp->link=NULL;

    temp->link=head;
    head=temp;

    return head;
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

void add_at_end(struct node *head,int data)
{
    struct node *temp=new struct node;
    temp->data=data;
    temp->link=NULL;

    struct node *ptr=head;

    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=temp;
}

int main()
{
    struct node *head=new struct node;
    int n,data;
    cout<<"Enter number of elements:";
    cin>>n;

    cout<<"Enter elements:"<<endl;
    cin>>data;

    head->data=data;
    head->link=NULL;

    for(int i=0; i<n-1; i++){
        cin>>data;
        add_at_end(head,data);
    }
    head=add_at_begin(head,90);

    print_data(head);
}
