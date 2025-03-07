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

struct node *return_tail(struct node *head)
{
    struct node *ptr=head;
    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    return ptr;
}

struct node *partition(struct node *first,struct node *last)
{
    struct node *pivot=first;
    struct node *front=first;
    int temp=0;

    while(front!=last){
        if(front->data < last->data){
            pivot=first;

            temp=front->data;
            front->data=first->data;
            first->data=temp;

            first=first->link;
        }
        front=front->link;
    }

    temp=first->data;
    first->data=last->data;
    last->data=temp;

    return pivot;
}

void quickSort(struct node *first,struct node *last)
{
    if(first==last)
        return;
    struct node* pivot=partition(first,last);

    if(pivot!=NULL && first!=pivot)
        quickSort(first,pivot);
    if(pivot!=NULL && pivot!=last){
        quickSort(pivot->link,last);
    }
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

    struct node *tail=return_tail(head);

    print_list(head);
    quickSort(head,tail);
    print_list(head);
}
