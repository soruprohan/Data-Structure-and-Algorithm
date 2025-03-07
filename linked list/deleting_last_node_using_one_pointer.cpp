#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *link;
};

void print_list(struct node *head)
{
    if(head==NULL)
        cout<<"The list is empty"<<endl;
    else{
        struct node *ptr=head;
        while(ptr!=NULL){
            cout<<ptr->data<<" ";
            ptr=ptr->link;
        }
        cout<<endl;
    }
}

struct node* add_at_end(struct node *head,int data)   //better complexity,when using loop in main to take input one after another,this process is better
{
    struct node *temp=new struct node;
    temp->data=data;
    temp->link=NULL;

    struct node *ptr=head;
    ptr->link=temp;
    return temp;
}

void delete_last(struct node *&head)
{

    if(head==NULL){
        cout<<"List is empty.Nothing to delete."<<endl;
        return;
    }
    if(head->link==NULL){
        delete head;
        head=NULL;
        return;
    }

    struct node *ptr=head;
    while(ptr->link->link!=NULL){
        ptr=ptr->link;
    }

    delete ptr->link->link;
    ptr->link=NULL;

}

int main()
{
    struct node *head=new struct node;
    int data,n;
    cout<<"Enter number of elements:"<<endl;
    cin>>n;
    cout<<"Enter data:";
    cin>>data;
    head->data=data;
    head->link=NULL;

    struct node *ptr=head;
    for(int i=0; i<n-1; i++){
        cin>>data;
        ptr=add_at_end(ptr,data);
    }

    print_list(head);
    delete_last(head);
    print_list(head);
}


