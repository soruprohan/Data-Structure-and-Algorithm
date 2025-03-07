#include<iostream>
#include<stack>
#include<string>
using namespace std;


bool check_brackets(string &s)
{
    stack<char> st;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
          st.push(s[i]);
        }
        else{
            if(st.empty())
                return false;
            else if((st.top()=='(' && s[i]==')') || (st.top()=='{' && s[i]=='}') || (st.top()=='[' && s[i]==']')){
                st.pop();
            }
            else
                return false;
        }
    }
    if(!st.empty())
        return false;

    return true;
}

int main()
{
    string s;
    cout<<"Enter brackets string:";
    cin>>s;
    cout<<check_brackets(s)<<endl;
}
