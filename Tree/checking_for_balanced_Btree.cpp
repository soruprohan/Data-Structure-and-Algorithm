#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node():data(0),left(nullptr),right(nullptr){}
    node(int x):data(x),left(nullptr),right(nullptr){}
};

void create(node* &root)
{
    queue<node*> q;
    node *ptr,*temp;
    vector<int> v(100,-1);
    int n,l,val;
    cout<<"Enter levels:";
    cin>>l;
    n=pow(2,l)-1;
    cout<<"Enter elements levelwise:"<<endl;
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
        if(val!=-1){
            temp=new node(val);
            ptr->left=temp;
            q.push(temp);
        }

        val=v[2*i+2];
        if(val!=-1){
            temp=new node(val);
            ptr->right=temp;
            q.push(temp);
        }
        i++;
    }
}

int check(node *root)
{
    if(root==nullptr)
        return 0;

    int lh=check(root->left);
    int rh=check(root->right);

    if (lh==-1 ||rh==-1)
        return -1;
    if(abs(lh-rh)>1)
        return -1;
    return 1+max(lh,rh);
}

int main()
{
    node *root=NULL;
    create(root);

    if(check(root)==-1)
        cout<<"Not balanced"<<endl;
    else
        cout<<"Balanced"<<endl;
}
