#include<bits/stdc++.h>
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
        node *ptr,*temp;
        queue<node*>q;
        int val,l,n;
        vector<int>v(100,-1);

        cout<<"Enter levels:";
        cin>>l;
        n=pow(2,l)-1;
        cout<<"Enter nodes levelwise:"<<endl;
        for(int i=0; i<n; i++){
            cin>>v[i];
        }

        root=new node(v[0]);
        q.push(root);
        int i=0;
        while(!q.empty()){
            if(v[i]==-1){
                i++;
            continue;
            }
            ptr=q.front();
            q.pop();

            val=v[2*i+1];
            if(val != -1){
                temp=new node(val);
                ptr->left=temp;
                q.push(temp);
            }

            val=v[2*i+2];
            if(val != -1){
                temp=new node(val);
                ptr->right=temp;
                q.push(temp);
            }
            i++;
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
