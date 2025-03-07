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

int count_list(struct node *head)
{
    int ct=0;
        struct node *ptr=head;
        while(ptr!=NULL){
            ct++;
            ptr=ptr->link;
        }

    return ct;
}

void add_at_end(struct node *&head,int data)
{
    struct node *temp=new struct node;
    temp->data=data;
    temp->link=NULL;

    if(head==NULL){
        head=temp;
    }
    else{
        struct node *ptr=head;
        while(ptr->link!=NULL){
            ptr=ptr->link;
        }
        ptr->link=temp;
    }
}

void reverse(struct node *&head)
{
    struct node *prev=NULL;
    struct node *next=NULL;

    while(head!=NULL){
        next=head->link;
        head->link=prev;
        prev=head;
        head=next;
    }
    head=prev;
}

struct node* summation(struct node *head1,struct node *head2)
{
    struct node *head3=new struct node;
    head3=NULL;

    reverse(head1);
    reverse(head2);

    int n1=count_list(head1);
    int n2=count_list(head2);
    int n,carry=0,data;
    if(n1>=n2)
        n=n1;
    else
        n=n2;

    for(int i=0; i<n; i++){
           add_at_end(head3,0);
    }

    struct node *ptr1=head1;
    struct node *ptr2=head2;
    struct node *ptr3=head3;


    for(int i=0; i<n; i++){

        if(ptr2!=NULL && ptr1!=NULL){
            ptr3->data=(ptr1->data+ptr2->data+carry);
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
        else if(ptr1!=NULL){
            ptr3->data=ptr1->data+carry;
            ptr1=ptr1->link;
        }
        else{
            ptr3->data=ptr2->data+carry;
            ptr2=ptr2->link;
        }
        if(ptr3->data > 9){
            ptr3->data=ptr3->data %10;
            carry=1;
        }
        else{
            carry=0;
        }
        ptr3=ptr3->link;
    }

    if(carry==1){
        add_at_end(head3,1);
    }

    reverse(head3);
    return head3;
}

int main()
{
    int n,data;
    struct node *head1=new struct node;
    head1=NULL;
    cout<<"No of elements in 1st list:";
    cin>>n;
    cout<<"Enter data:";
    for(int i=0; i<n; i++){
            cin>>data;
        add_at_end(head1,data);
    }
    //print_list(head1);

    struct node *head2=new struct node;
    head2=NULL;
    cout<<"No of elements in 2nd list:";
    cin>>n;
    cout<<"Enter data:";
    for(int i=0; i<n; i++){
            cin>>data;
        add_at_end(head2,data);
    }
   // print_list(head2);

    struct node *head3= summation(head1,head2);

    cout<<"The result is:";
    print_list(head3);
}



