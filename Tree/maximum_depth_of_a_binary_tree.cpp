#include<bits/stdc++.h>
#include<cstring>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node():data(0),left(nullptr),right(nullptr){}
    node(int x):data(x),left(nullptr),right(nullptr){}
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

int max_depth(node * root)
{
    if (root==nullptr)
        return 0;
    int lh=max_depth(root->left);
    int rh=max_depth(root->right);

    return 1+max(lh,rh);
}

int main()
{
    node *root=NULL;
    create(root);

    cout<<max_depth(root->left)<<endl;
}


