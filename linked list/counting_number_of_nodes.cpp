#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *link;
};

void count_of_nodes(struct node *head)
{
    int count=0;

    if(head==NULL)
        cout<<"Linked list is empty."<<endl;
    struct node *ptr=head;
    while(ptr!=NULL){
        count++;
        ptr=ptr->link;
    }
    cout<<count<<endl;
}

int main()
{
    struct node *head=new struct node;
    head->data =45;
    head->link=NULL;

    struct node *current=new struct node;
    current->data=98;
    current->link=NULL;
    head->link=current;

    current=new struct node;
    current->data=3;
    current->link=NULL;
    head->link->link=current;

//    cout<<head->data<<endl;
//    cout<<head->link->data<<endl;
//    cout<<head->link->link->data<<endl;

    count_of_nodes(head);
    return 0;
}


