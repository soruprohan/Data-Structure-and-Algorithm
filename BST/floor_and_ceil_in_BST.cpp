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

int floor(node *root,int key)
{
    node *cur=root;
    int Floor=-1;

    while(cur!=nullptr){
        if(key == cur->data){
            Floor=key;
            break;
        }
        else if(key < cur->data){
            cur=cur->left;
        }
        else{
            Floor=cur->data;
            cur=cur->right;
        }
    }
    return Floor;
}

int ceil(node *root,int key)
{
   node *cur=root;
   int Ceil=-1;

   while(cur!=nullptr){
        if(key==cur->data){
            Ceil=key;
            break;
        }
        else if(key < cur->data){
            Ceil=cur->data;
            cur=cur->left;
        }
        else{
            cur=cur->right;
        }
   }
   return Ceil;
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
    cout<<"Enter number to find floor & ceil:";
    cin>>x;

    cout<<"Floor is: "<<floor(root,x)<<endl;
    cout<<"Ceil is: "<<ceil(root,x)<<endl;

}

