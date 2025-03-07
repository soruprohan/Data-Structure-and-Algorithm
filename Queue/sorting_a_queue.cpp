#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    stack<int>st;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        q.push(x);
    }
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        while(!st.empty() && st.top() < temp){
            q.push(st.top());
            st.pop();
        }
        st.push(temp);
    }

    for(int i=0; i<n; i++){
        q.push(st.top());
        st.pop();
    }

    for(int i=0; i<n; i++){
        int temp=q.front();
        cout<<temp<<" ";
        q.pop();
        q.push(temp);           //this makes sure that the queue is not empty after printing it
    }

}
