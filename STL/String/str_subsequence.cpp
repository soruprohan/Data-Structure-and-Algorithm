#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;

    stack<char> st;

    for(int i=0; i<s.size(); i++){
        while(!st.empty() && s[i] > st.top())
            st.pop();

        st.push(s[i]);
    }
    string res="";

    while(!st.empty()){
        res=res+st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());

    cout<<res<<endl;
}
