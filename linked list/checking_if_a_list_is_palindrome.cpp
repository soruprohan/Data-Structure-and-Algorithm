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

bool check_list(struct node *&head)
{
   int n=count_list(head);
   int arr[n];

   struct node *ptr=head;

   while(ptr!=NULL){
        arr[--n]=ptr->data;
        ptr=ptr->link;
   }

   ptr=head;
   int i=0;
   while(ptr!=NULL){
        if(ptr->data !=arr[i++])
            return false;
        ptr=ptr->link;
   }
   return true;
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

   // print_list(head);
    if(check_list(head))
        cout<<"palindrome"<<endl;
    else
        cout<<"Not palindrome"<<endl;

}
