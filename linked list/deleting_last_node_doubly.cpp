#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void print_list(struct node *head)
{
    struct node *ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}


void delete_last(struct node *head)
{
    struct node *ptr=head,*temp=head;

    while(ptr->next!=NULL){
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next=NULL;
    delete ptr;

}

struct node* add_at_end(struct node *ptr,int data) //better complexity
{
    struct node *temp=new struct node;
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;

    ptr->next=temp;
    temp->prev=ptr;

    return temp;
}

int main()
{
    int n,data,pos;
    cout<<"Enter number of elements:";
    cin>>n;
    cout<<"Enter elements:";
    cin>>data;
    struct node *head=new struct node;
    head->prev=NULL;
    head->data=data;
    head->next=NULL;

    struct node *ptr=head;

    for(int i=0; i<n-1; i++){
        cin>>data;
        ptr=add_at_end(ptr,data);
    }
    print_list(head);
    delete_last(head);
    print_list(head);
}


