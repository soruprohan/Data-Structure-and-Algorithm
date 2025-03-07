#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node():data(0),left(NULL),right(NULL){}
    node(int x):data(x),left(NULL),right(nullptr){}
    node(int x,node *l,node *r):data(x),left(l),right(r){}
};

void preorder(node*);
void inorder(node*);
void postorder(node*);

class Btree
{
    node *root;
public:

    Btree()
    {
        root=NULL;
    }
    Btree(int val)
    {
        root=new node(val);
    }
    Btree(int val,node *l,node *r)
    {
        root=new node(val,l,r);
    }
    ~Btree()
    {
        delete root;
    }

    void createManual()
    {
        queue<node*>q;
        int val;
        node *ptr,*temp;

        cout<<"Enter root node:";
        cin>>val;

        root=new node(val);
        q.push(root);

        while(!q.empty()){
            ptr=q.front();
            q.pop();

            cout<<"Enter left child of "<<ptr->data<<":";
            cin>>val;
            if(val!=-1){
                temp=new node(val);
                ptr->left=temp;
                q.push(temp);
            }
            cout<<"Enter right node of "<<ptr->data<<":";
            cin>>val;
            if(val!=-1){
                temp=new node(val);
                ptr->right=temp;
                q.push(temp);
            }
        }
    }

     void createLevelwise()
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


    //there is no way for a member function to be recursive within a class,you must have two functions
    //or you can make the data member public ,but then again,the traversal functions are really not member functions
    //but global function that will access public data member,so this is the only way to make recursive member functions
    void PREorder()
    {
        preorder(root);
    }

    void INorder()
    {
        inorder(root);
    }
    void POSTorder()
    {
        postorder(root);
    }

};

//these are global funtions
    void preorder(node *root)
    {
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    }

    void inorder(node *root)
    {
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    }

    void postorder(node *root)
    {
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    }

int main()
{
    Btree ob;
    ob.createLevelwise();

    ob.INorder();
}
