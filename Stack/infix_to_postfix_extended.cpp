#include<iostream>
#include<cstring>
#include<stack>

using namespace std;

bool isOperand(char c)
{
    if(c!='+' && c!='-' && c!='*' && c!='/' && c!='(' && c!=')')
        return true;
    else
        return false;
}

int prec(char c)
{
    if(c=='^')
        return 3;
    else if(c=='*' || c=='/')
        return 2;
    else if(c=='+' || c=='-')
        return 1;

    return 0;
}

char asscociativity(char c)
{
    if(c=='^')
        return 'R';
    else
        return 'L';
}

int main()
{
    stack<int> st;
    string in,post;
    cout<<"Enter infix expression: ";
    cin>>in;

    for(int i=0; i<in.size(); i++){
        if(isOperand(in[i]))
            post+=in[i];

        else if(in[i]=='(')
            st.push(in[i]);
        else if(in[i]==')'){
            while(st.top()!='('){
                  post+=st.top();
                  st.pop();
            }
            st.pop();
        }
        else{
            if(!st.empty() && prec(in[i]) <= prec(st.top()) && asscociativity(in[i])=='L'){
                    post+=in[i];
                st.pop();
            }
            else
                st.push(in[i]);
        }
    }
    cout<<"The postfix expression is: "<<post<<endl;
}
