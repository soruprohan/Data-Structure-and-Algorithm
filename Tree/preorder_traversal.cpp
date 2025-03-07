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

void print(vector<int> &v)
{
    for(int &it2 :v){
        cout<<it2<<" ";
    }
    cout<<endl;
}

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


void it_preorder(node *root,vector<int> &ans)
{
    if(root==nullptr)
        return;
    stack<node*>st;
    node *ptr;
    st.push(root);

    while(!st.empty()){
        ptr=st.top();
        st.pop();

        if(ptr->right!=NULL)
            st.push(ptr->right);
        if(ptr->left!=NULL)
            st.push(ptr->left);

        ans.push_back(ptr->data);
    }
}

void recur_preorder(node *root)
{
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    recur_preorder(root->left);
    recur_preorder(root->right);
}

int main()
{
    node *root=NULL;
    create(root);

    vector<int> ans;
    it_preorder(root,ans);
    print(ans);
    recur_preorder(root);
}


