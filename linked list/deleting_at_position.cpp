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

void delete_pos(struct node *&head,int pos)
{
    if(head==NULL){
        cout<<"Empty list.cannot be deleted"<<endl;
        return;
    }

    struct node *ptr=head,*temp=head;
    if(pos==0){
        head=head->link;
        delete ptr;
        return;
    }


    for(int i=0; i<pos; i++){
        temp=ptr;
        ptr=ptr->link;
    }

    temp->link=ptr->link;
    delete ptr;

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
    int pos;
    cout<<"Enter position to delete:";
    cin>>pos;
    delete_pos(head,pos);
    print_list(head);
}

