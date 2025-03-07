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

/*
    Time complexity: O(N)
    Space complexity: O(N)

    Where 'N' is the number of elements in the array 'arr'
*/
node* create(vector<int>& arr)
{
    queue<node*> q;
    // Create the root node with the value from the first element of the array
    node* root = new node(arr[0]);
    q.push(root);

    int i = 0;

    // Construct the binary tree using the remaining elements of the array
    while (!q.empty() && i < 3) {
        node* t = q.front();
        q.pop();

        // Create the left child node with the value from the corresponding index in the array
        node* left = new node(arr[2 * i + 1]);
        t->left = left;
        q.push(left);

        // Create the right child node with the value from the corresponding index in the array
        node* right = new node(arr[2 * i + 2]);
        t->right = right;
        q.push(right);
        i++;
    }
    return root;
}

void recur_postorder(node *root)
{
    if(root==NULL)
        return;
    recur_postorder(root->left);
    recur_postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    node *root=NULL;
    vector<int> v(100);
    int n;
    cout<<"n:";
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    root=create(v);

//    it_postorder(root);
    recur_postorder(root);
}


