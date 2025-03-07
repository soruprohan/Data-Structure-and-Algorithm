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
    else if(data < root->data)
        root->left= insert(root->left,data);
    else
        root->right=insert(root->right,data);
    return root;
}

node* del(node *root,int val)
{
    if(root==nullptr)
        return root;

    if(val < root->data ){
        root->left= del(root->left,val);
    }
    else if(val >root->data){
        root->right=del(root->right,val);
    }
    else{
        if(root->left==nullptr && root->right==nullptr){
            delete root;
            root=nullptr;
            return root;
        }
        else if(root->left==nullptr && root->right!=nullptr){
            node *temp=root;
            root=root->right;
            delete temp;
            return root;
        }
        else if(root->left!=nullptr && root->right==nullptr){
            node *temp=root;
            root=root->left;
            delete temp;
            return root;
        }
        else{
            node *cur=root,*prev=root;
            cur=cur->right;
            while(cur->left!=nullptr){
                prev=cur;
                cur=cur->left;
            }
            root->data=cur->data;
            delete cur;
            prev->left=nullptr; //because now the place of inorder successor should be null,and the node whose Left child is that node should now point Left to null
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
    cout<<"Enter number of nodes:";
    int n; cin>>n;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        root=insert(root,x);
    }

    inorder(root);  cout<<endl;
    cout<<"Enter node to delete:";
    int x; cin>>x;
    root=del(root,x);
    inorder(root); cout<<endl;
}

