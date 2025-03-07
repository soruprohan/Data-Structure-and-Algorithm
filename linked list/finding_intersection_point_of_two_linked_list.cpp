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

//struct node* find_intersection(struct node *head1,struct node *head2)
//{
//    struct node *ptr1=head1;
//    struct node *ptr2=head2;
//    while(ptr1!=NULL){
//        while(ptr2!=NULL){
//            if(ptr1==ptr2)
//                return ptr1;
//            ptr2=ptr2->link;
//        }
//        ptr2=head2;
//        ptr1=ptr1->link;
//    }
//    return NULL;
//}

//better complexity

struct node* find_intersection(struct node *head1, struct node *head2) {
    int len1 = count_list(head1);
    int len2 = count_list(head2);

    int diff = abs(len1 - len2);

    struct node *ptr1 = (len1 > len2) ? head1 : head2;
    struct node *ptr2 = (len1 > len2) ? head2 : head1;

    for (int i = 0; i < diff; i++) {
        if (ptr1 == NULL)
            return NULL;
        ptr1 = ptr1->link;
    }

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2)
            return ptr1;
        ptr1 = ptr1->link;
        ptr2 = ptr2->link;
    }

    return NULL;
}




int main()
{
    int n,data;
    struct node *head1=new struct node;
    head1=NULL;

    cout<<"Enter data:";
    for(int i=0; i<5; i++){
            cin>>data;
        add_at_end(head1,data);
    }
    //print_list(head1);

    struct node *head2=new struct node;
    head2=NULL;

    cout<<"Enter data:";
    for(int i=0; i<3; i++){
            cin>>data;
        add_at_end(head2,data);
    }

    head2->link->link->link=head1->link->link; //This is to create a intersection point at 1st list's 3rd node

    struct node *intersect=find_intersection(head1,head2);

    if(intersect!=NULL)
        cout<<intersect<<"  "<<intersect->data<<endl;
    else
        cout<<"No intersection point found."<<endl;
}
