#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void print_list(struct node *head)
{
    struct node *ptr=head;
    if(head==NULL){
        cout<<"The list is empty."<<endl;
        return;
    }
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

struct node* add_at_end(struct node *ptr,int data)
{
    struct node *temp=new struct node;
    temp->data=data;
    temp->prev=NULL;
    temp->next=NULL;

    ptr->next=temp;
    temp->prev=ptr;
    return temp;

}

void reverse_list(struct node *&head)
{
    struct node *temp;

    while(head!=NULL){
    temp=head->prev;  //This line is very crucial,don't use temp=head->next for swapping,then temp will be NULL for the last node and you wont be able to set head to last node
    head->prev=head->next;
    head->next=temp;

    head=head->prev;
    }

    head=temp->prev;
}

int main()
{
     int data,n;

    cout<<"Enter number of elements:";
    cin>>n;

    cout<<"Enter data:";
    cin>>data;

    struct node *head=new struct node;
    head->prev=NULL;
    head->next=NULL;
    head->data=data;

    struct node *ptr=head;
    while(--n){
        cin>>data;
        ptr=add_at_end(ptr,data);
    }

    print_list(head);

    reverse_list(head);
    print_list(head);
}
