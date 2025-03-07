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
    if(head==NULL){
        cout<<"The list is empty."<<endl;
        return;
    }
    struct node *ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}


void delete_data(struct node *&head,int data)
{
    struct node *ptr=head,*temp=head;

    //This is to handle if list has only one element
    if(head->next==NULL){
        delete head;
        head=NULL;
        return;
    }

    //This is to handle the first element
    if(head->data==data){
        head=head->next;
        head->prev=NULL;
        delete ptr;
        return;
    }

    while(ptr!=NULL && ptr->data!=data){
        temp=ptr;
        ptr=ptr->next;
    }

    if(ptr==NULL){
        cout<<"Data not found."<<endl;
        return;
    }
    //This is to handle last element
    if(ptr->next==NULL){
        temp->next=NULL;
        delete ptr;
        return;
    }

    temp->next=ptr->next;
    ptr->next->prev=temp;
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
    cout<<"Enter data to delete:";
    cin>>data;
    delete_data(head,data);
    print_list(head);
}



