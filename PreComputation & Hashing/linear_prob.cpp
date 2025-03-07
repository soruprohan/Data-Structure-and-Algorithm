#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *both;
};

class XORList
{
    struct node *head;
public:
    XORList()
    {
        head=NULL;
    }
    node* XOR(node *a,node *b)
    {
        return (node*)((long long ) a ^ (long long) b);
    }

    void insert_at_beg(int data)
    {
        struct node *temp=new struct node;
        temp->data=data;
        temp->both=NULL;

        if(head==NULL){
            head=temp;
        }
        else{
            head->both=XOR(XOR(NULL,head->both),temp);
            temp->both=XOR(NULL,head);
            head=temp;
        }
        
    }

    void insert_at_pos(int data,int pos)
    {
        if(pos<=0){
            cout<<"Invalid position"<<endl;
            return;
        }
        struct node *temp=new struct node;
        temp->data=data;
        temp->both=NULL;

        struct node *next,*prev=NULL,*ptr=head;

        for(int i=0; i<pos; i++){
            next=XOR(ptr->both,prev);
            prev=ptr;
            ptr=next;
        }
        prev->both=XOR(XOR(prev->both,ptr),temp);
        temp->both=XOR(prev,ptr);
    }

    void insert_at_end(int data)
    {
        struct node *temp=new struct node;
        temp->data=data;
        temp->both=NULL;

        struct node *ptr=head;
        struct node *prev=NULL;
        struct node *next;

         if(head==NULL){
            head=temp;
            return;
        }

        while(ptr!=NULL){
            next=XOR(ptr->both,prev);
            prev=ptr;
            ptr=next;
        }

        ptr=prev;       //now ptr points at last node of the list

        ptr->both=XOR(XOR(NULL,ptr->both),temp);
        temp->both=XOR(ptr,NULL);
        
    }

    void delete_at_beg()
    {
        if(head==NULL)
            return;
        if(head->both==NULL){
            delete head;
            head=NULL;
            return;
        }

        struct node *next=head;
        next=XOR(head->both,NULL);

        next->both=XOR(XOR(next->both,head),NULL);

        delete head;
        head=next;
    }

    void delete_at_end()
    {
        if(head==NULL)
            return;
        if(head->both==NULL){
            delete head;
            head=NULL;
            return;
        }
        
        struct node *ptr=head,*prev=NULL,*next;
        while(ptr!=NULL){
            next=XOR(ptr->both,prev);
            prev=ptr;
            ptr=next;
        }

         ptr=prev;       //now ptr points at last node of the list
         prev=XOR(prev->both,NULL); //prev last er ager node point kore ekhon

         prev->both=XOR(XOR(prev->both,ptr),NULL);
         delete ptr;

    }

    void traverse_front()
    {
        struct node *ptr=head;
        struct node *prev=NULL;
        struct node *next;

        while(ptr!=NULL){
            cout<<ptr->data<<endl;
            next=XOR(ptr->both,prev);
            prev=ptr;
            ptr=next;
        }
        cout<<endl;
    }
    
};

int main()
{
    XORList list;
	list.insert_at_beg(10);
	list.insert_at_beg(20);
	list.traverse_front();
	list.insert_at_end(30);
	list.insert_at_end(40);
	list.traverse_front();
	// prints 20 10 30 40

	list.delete_at_beg();
	// prints 10 30 40
	list.traverse_front();
	list.delete_at_end();
	// prints 10 30
	list.traverse_front();
	return 0;
}
