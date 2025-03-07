#include<iostream>
#include<stack>
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

bool check_loop(struct node *head)
{
    struct node *slow=head;
    struct node *fast=head;

    while(fast!=NULL && fast->link!=NULL){

     slow=slow->link;
    fast=fast->link->link;
        if(slow==fast)
            return true;

    }
    return false;
}

int main()
{
    struct node *head=new struct node;
    int data,n;
    cout<<"Enter number of elements:";
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

    ptr->link=head->link; //this is just to create a loop
   // print_list(head);
    if(check_loop(head))
        cout<<"Loop exists"<<endl;
    else
        cout<<"Loop doesn't exist"<<endl;

}


