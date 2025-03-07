#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node():data(0),left(NULL),right(NULL){}
    node(int x):data(x),left(NULL),right(NULL){}
    node(int x,node *l,node *r):data(x),left(l),right(r){}
};

node* helper(node*);
node* findlastright(node*);

node* insert(node *root,int data)
{
    if(root==NULL)
        return new node(data);
    node *cur=root;
    while(true){
        if(data> cur->data){
            if(cur->right==NULL){
                cur->right=new node(data);
                break;
            }
            else
                cur=cur->right;
        }
        else{
            if(cur->left==NULL){
                cur->left=new node(data);
                break;
            }
            else
                cur=cur->left;
        }
    }
    return root;
}

node* del(node *root,int key)
{
    if(root==NULL)
        return NULL;
    if(root->data==key)
        return helper(root);

    node* dummy=root;
    while(root!=NULL){
        if(key<root->data){
            if(root->left!=NULL && root->left->data==key){
                root->left=helper(root->left);
                break;
            }
            else{
                root=root->left;
            }
        }
        else{
            if(root->right!=NULL && root->right->data==key){
                root->right=helper(root->right);
                break;
            }
            else{
                root=root->right;
            }
        }
    }
    return dummy;
}

node* helper(node *root)
{
    if(root->left==NULL)
        return root->right;
    else if(root->right==NULL)
        return root->left;
    else{
        node* rightchild=root->right;
        node* lastright=findlastright(root->left);
        lastright->right=rightchild;
        return root->left;
    }
}

node* findlastright(node *root)
{
    while(root->right!=NULL)
        root=root->right;
    return root;
}

void inorder(node *root)
{
    if(root==NULL)
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
    inorder(root);
}
