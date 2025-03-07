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


void it_inorder(node *root,vector<int> &ans)
{
    if(root==nullptr)
        return;
   stack<node*>st;
   node* ptr=root;

   while(true){
        if(ptr!=nullptr){
            st.push(ptr);
            ptr=ptr->left;
        }
        else{
            if(st.empty())
                break;
            ptr=st.top();
            st.pop();
            ans.push_back(ptr->data);
            ptr=ptr->right;
        }
   }
}

void recur_inorder(node *root)
{
    if(root==NULL)
        return;
    recur_inorder(root->left);
    cout<<root->data<<" ";
    recur_inorder(root->right);
}

int main()
{
    node *root=NULL;
    create(root);

    vector<int> ans;
    it_inorder(root,ans);
    print(ans);
    recur_inorder(root);
}

