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

struct node *find_middle(struct node *head)
{
    struct node *slow=head;
    struct node *fast=head->link;

    while(fast!=NULL && fast->link!=NULL){
        fast=fast->link->link;
        slow=slow->link;
    }

    return slow;
}

struct node *merge(struct node *t1,struct node *t2)
{
    struct node *dummy=new struct node;
    struct node *temp=dummy;

    while(t1!=NULL && t2!=NULL){
        if(t1->data < t2->data){
            temp->link=t1;
            temp=t1;
            t1=t1->link;
        }
        else{
            temp->link=t2;
            temp=t2;
            t2=t2->link;
        }
    }
    if(t1!=NULL)
        temp->link=t1;
    else
        temp->link=t2;

    return dummy->link;
}

struct node *mergeSort(struct node *head)
{
    if(head==NULL || head->link==NULL)
        return head;

    struct node *middle=find_middle(head);
    struct node *lefthead=head;
    struct node *righthead=middle->link;
    middle->link=NULL;

    lefthead=mergeSort(lefthead);
    righthead=mergeSort(righthead);

    return merge(lefthead,righthead);
}

int main()
{
    int n,data;
    struct node *head=new struct node;
    head=NULL;
    cout<<"No of elements in 1st list:";
    cin>>n;
    cout<<"Enter data:";
    for(int i=0; i<n; i++){
            cin>>data;
        add_at_end(head,data);
    }


    print_list(head);
    head=mergeSort(head);
    print_list(head);
}

