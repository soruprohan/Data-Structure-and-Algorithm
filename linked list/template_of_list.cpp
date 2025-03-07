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

struct node* add_at_beg(struct node *head,int data)
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
    int data;
    while(true){
        cout<<"To create a linked list press 1"<<endl;
        cout<<"To add at end of list press 2"<<endl;
        cout<<"To add at at beginning press 3"<<endl;
        cout<<"To add at a certain position press 4"<<endl;
        cout<<"To print the list press 5"<<endl;
        cout<<"To exit press 6"<<endl<<endl;
        int key;
        cout<<"Enter your choice:";
        cin>>key;
        if(key==1){
            cout<<"Enter data:";
            cin>>data;
            head->data=data;
            head->link=NULL;
            cout<<"Linked list created successfully."<<endl;
        }
        if(key==2){
            cout<<"Enter data:";
            cin>>data;
            add_at_end(head,data);
        }
        if(key==3){
            cout<<"Enter data:";
            cin>>data;
            head=add_at_beg(head,data);
        }
        if(key==4){
            cout<<"Enter data:";
            cin>>data;
            int pos;
            cout<<"Enter position:";
            cin>>pos;
            add_at_pos(head,data,pos);
        }
        if(key==5){
            print_list(head);
        }
        if(key==6){
            cout<<"Exiting now. . ."<<endl;
            break;
        }
    }
}

