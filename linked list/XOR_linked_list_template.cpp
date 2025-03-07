#include<iostream>
#include<cstdint>
using namespace std;

struct node
{
    int data;
    struct node *both;
};


class XORList{

    struct node *head;
    struct node *tail;
public:
    XORList()
    {
        head=tail=NULL;
    }

    node* XOR(node *a,node *b)
    {
        return ((node*) (uintptr_t(a) ^ uintptr_t(b)));
    }

    void insert_at_beg(int data)
    {
        struct node *temp=new struct node;
        temp->data=data;
        temp->both=XOR(head,NULL);

        if(head==NULL){
            head=temp;
            tail=temp;
        }

        else{
            head->both=XOR(XOR(head->both,NULL),temp);
            head=temp;
        }

    }

    void insert_at_end(int data)
    {
        struct node *temp=new struct node;
        temp->data=data;
        temp->both=XOR(tail,NULL);

        if(tail==NULL){
            head=temp;
            tail=temp;
        }
        else{
            tail->both=XOR(XOR(tail->both,NULL),temp);
            tail=temp;
        }

    }

    void delete_at_beg()
    {
        if(head==NULL)
            return;
        if(head->both==NULL){
            delete head;
            head=NULL;
            tail=NULL;
            return;
        }

        struct node *temp=head;
        struct node *next=XOR(head->both,NULL);
        head=next;

        head->both=XOR(XOR(head->both,temp),NULL);
        delete temp;
    }

    void delete_at_end()
    {
        if(tail==NULL)
            return;
        if(tail->both==NULL){
            delete tail;
            tail=NULL;
            head=NULL;
            return;
        }
        struct node *temp=tail;
        struct node *prev=XOR(tail->both,NULL);

        tail=prev;
        tail->both=XOR(XOR(tail->both,temp),NULL);
        delete temp;
    }

    void traverse_front()
    {
        struct node *ptr=head;
        struct node *prev=NULL;
        struct node *next;
        while(ptr!=NULL){
            cout<<ptr->data<<" ";
            next=XOR(prev,(ptr->both));
            prev=ptr;
            ptr=next;

    }
        cout<<endl;
    }

    void traverse_back()
    {
        struct node *ptr=head;
        struct node *prev;
        struct node *next=NULL;

        while(ptr!=NULL){
            cout<<ptr->data<<" ";
            prev= XOR(next,(ptr->both));
            next=ptr;
            ptr=prev;
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
