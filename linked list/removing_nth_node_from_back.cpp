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

struct node* add_at_end(struct node *head,int data)   //better complexity,when using loop in main to take input one after another,this process is better
{
    struct node *temp=new struct node;
    temp->data=data;
    temp->link=NULL;

    struct node *ptr=head;
    ptr->link=temp;
    return temp;
}

void delete_node(struct node *&head,int pos)
{
    int n=count_list(head);
    struct node *temp,*ptr=head;

    if(pos<=0 || pos>n){
        cout<<"Invalid position"<<endl;
        return;
    }
    if(head->link==NULL){
        delete head;
        head=NULL;
        return;
    }
    n=n-pos-1;
    if(n<0){
        head=head->link;
        delete ptr;
        return;
    }

    for(int i=0; i<n; i++){
         ptr=ptr->link;
    }
    temp=ptr->link;
    ptr->link=temp->link;
    delete temp;
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

    cout<<"Enter node to delete from back:";
    cin>>data;

    print_list(head);
    delete_node(head,data);
    print_list(head);
}
