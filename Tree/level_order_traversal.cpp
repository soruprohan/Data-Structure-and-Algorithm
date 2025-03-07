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

void print(vector<vector<int>> &v)
{
    for(auto &it: v){
        for(int &it2 :it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
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


vector<vector<int>> bfs(node* root)
{
    vector<vector<int>> ans;
    queue<node*> q;

    if(root==NULL)
        return ans;     //returns empty vector

    q.push(root);
    node *ptr;

    while(!q.empty()){
        int size=q.size();
        vector<int>level;
        for(int i=0; i<size; i++){
            ptr=q.front();
            q.pop();

            if(ptr->left!=NULL)
                q.push(ptr->left);
            if(ptr->right!=NULL)
                q.push(ptr->right);

            level.push_back(ptr->data);
        }
        ans.push_back(level);
    }
    return ans;
}

int main()
{
    node *root=NULL;
    create(root);

    vector<vector<int>> ans=bfs(root);
    print(ans);
}
