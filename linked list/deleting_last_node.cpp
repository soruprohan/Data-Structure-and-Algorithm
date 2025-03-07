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
        cout<<"Empty list.cannot be deleted"<<endl;
        return;
    }
    if(head->link==NULL){                   //has a single element,will occur error for delete_last if we don't consider this case,but works fine for delete_first
                                            //because there head is set to NULL as part of the algorithm,but here head is undefined if we delete the only node
//        struct node *ptr=head;
//        delete ptr;
        delete head; //it deletes what head points to,not head
        head=NULL;
        return ;
    }
    struct node *ptr=head,*temp=head;
    while(ptr->link!=NULL){
        temp=ptr;
        ptr=ptr->link;
    }
    temp->link=NULL;
    delete ptr;
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

