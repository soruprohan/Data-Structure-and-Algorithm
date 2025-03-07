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

void Swap(struct node *head,int data)
{
    struct node *prev=NULL,*next=NULL;
    struct node *ptr=head;

    while(ptr->link!=NULL && ptr->data!=data){
        prev=ptr;
        ptr=ptr->link;
    }
    next=ptr->link;
    ptr->link=next->link;
    prev->link=next;
    next->link=ptr;
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

    print_list(head);
    int x;
    cout<<"data:";  cin>>x;
    Swap(head,x);
    print_list(head);
}

