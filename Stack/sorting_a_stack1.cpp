#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int>st,st1;
    int n,temp;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>temp;
        st.push(temp);
    }
    while(!st.empty()){
        temp=st.top();
        st.pop();
        while(!st1.empty() && (st1.top() > temp))
        {
            st.push(st1.top());
            st1.pop();
        }
        st1.push(temp);
    }
    for(int i=0; i<n; i++){
        st.push(st1.top());
        st1.pop();
    }

    st1=st;     //this is to not pop the elements out of the given stack
    for(int i=0; i<n; i++){
        cout<<st1.top()<<endl;
        st1.pop();
    }
}
