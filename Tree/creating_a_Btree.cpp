#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node() : data(0),left(nullptr),right(nullptr){}
    node(int val) : data(val),left(nullptr),right(nullptr){}
    node(int val,node *left,node *right) : data(val),left(left),right(right){}
};

void create(node *&root)
{
    node *ptr=NULL,*temp=NULL;
    queue<node*>q;
    int val;
    cout<<"Enter root node:";
    cin>>val;
    root = new node(val);
    q.push(root);

    while(!q.empty())
    {
        ptr=q.front();
        q.pop();
        cout<<"Enter left child of "<<ptr->data<<" : ";
        cin>>val;
        if(val!=-1){
            temp=new node(val);
            ptr->left=temp;
            q.push(temp);
        }
        cout<<"Enter right child of "<<ptr->data<<" : ";
        cin>>val;
        if(val!=-1){
            temp=new node(val);
            ptr->right=temp;
            q.push(temp);
        }
    }


}

void inorder(node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node *root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if(root==NULL)
        return ;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    node *root=NULL;
    create(root);
    preorder(root);
}
