#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *link;
};

int main()
{
    struct node *head=(struct node *) malloc(sizeof(struct node));
    head->data =45;
    head->link=NULL;

    struct node *current=(struct node*)malloc(sizeof(struct node));
    current->data=98;
    current->link=NULL;
    head->link=current;

    struct node *current2= new struct node;
    current2->data=3;
    current2->link=NULL;
    current->link=current2;

    cout<<head->data<<endl;
    cout<<current->data<<endl;
    cout<<current2->data<<endl;

    return 0;
}
