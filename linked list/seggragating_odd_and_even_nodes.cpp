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

void seggregate(struct node *head)
{
    struct node *temp1,*temp2,*ptr1,*head_link;

    if(head==NULL || head ->link==NULL)
        return;

    temp1=head;
    temp2=head->link;
    head_link=head->link;

    while(temp1!=NULL && temp1->link!=NULL){
        ptr1=temp1;
        temp1->link=temp1->link->link;
        temp1=temp1->link;

        if(temp2->link!=NULL){
        temp2->link=temp2->link->link;
        temp2=temp2->link;
        }
    }
    if(temp1==NULL){
        ptr1->link=head_link;
    }
    else{
        temp1->link=head_link;
    }

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
    seggregate(head);
    print_list(head);
}
