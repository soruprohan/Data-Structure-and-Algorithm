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

//This function will show a msg if you try to add at beginning or end
void add_at_pos(struct node *&head,int data,int pos)
{
    struct node *temp=new struct node;
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;

    if(pos<=0){
         cout<<"Invalid position.Element not added."<<endl;
         return;
    }

    struct node *ptr=head;
    for(int i=0; i<pos-1; i++){
        if(ptr->next->next==NULL){
            cout<<"Invalid position.Element not added."<<endl;
            return;
        }
        ptr=ptr->next;
    }

    temp->next=ptr->next;
    temp->prev=ptr;
    ptr->next->prev=temp;
    ptr->next=temp;
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
    cout<<"Enter position and data:"<<endl;
    cin>>pos>>data;
    add_at_pos(head,data,pos);
    print_list(head);
}

