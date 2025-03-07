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

node* recur_search(node *root,int key)
{
    if(root==nullptr)
        return root;
    if(key==root->data)
        return root;
    else if(key < root->data)
        return recur_search(root->left,key);
    else
        return recur_search(root->right,key);
}

node* it_search(node *root,int key)
{
    while(root!=nullptr && key!=root->data){
        root=key < root->data ? root->left : root->right;
    }
    return root;
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

    int x;
    cout<<"Enter element to search:";
    cin>>x;
    if(recur_search(root,x)!=nullptr)
        cout<<"present"<<endl;
    else
        cout<<"not present"<<endl;

    if(it_search(root,x)!=nullptr)
        cout<<"present"<<endl;
    else
        cout<<"not present"<<endl;

}
