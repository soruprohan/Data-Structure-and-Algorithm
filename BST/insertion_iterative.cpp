#include<iostream>
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

node* insert(node *root,int data)
{
    if(root==nullptr)
        return new node(data);

    node *cur=root;
    while(true){
        if(data < cur->data){
            if(cur->left == nullptr){
                cur->left=new node(data);
                break;
            }
            else
                cur=cur->left;
        }
        else{
            if(cur->right == nullptr){
                cur->right=new node(data);
                break;
            }
            else
                cur=cur->right;
        }
    }
    return root;
}

void inorder(node *root)
{
    if(root==nullptr)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    node *root=nullptr;

    root=insert(root,10);
    root=insert(root,5);
    root=insert(root,13);
    root=insert(root,6);
    inorder(root);
}

