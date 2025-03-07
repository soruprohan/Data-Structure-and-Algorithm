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

void add_at_end(struct node *head,int data)
{
    struct node *temp=new struct node;
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;

    struct node *ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->prev=ptr;
}

int main()
{
    int n,data;
    cout<<"Enter n:";
    cin>>n;
    cout<<"Enter elements:";
    cin>>data;
    struct node *head=new struct node;
    head->prev=NULL;
    head->data=data;
    head->next=NULL;


    for(int i=0; i<n-1; i++){
        cin>>data;
        add_at_end(head,data);
    }
    print_list(head);
}

