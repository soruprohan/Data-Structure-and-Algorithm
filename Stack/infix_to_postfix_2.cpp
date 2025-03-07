#include<iostream>
#include<stack>
#include<cstring>
#include<string>

using namespace std;

bool isOperand(char c)
{
    if(c!='+' && c!='-' && c!='*' && c!='/')
        return true;
    else
        return false;
}

int precedence(char c)
{
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 2;
    else
        return 0;
}

int main()
{
     stack<char> st;
     string infix,postfix;
     cout<<"Enter infix expression:";
     cin>>infix;

     int i,j;
     i=j=0;
     while(infix[i]!='\0'){
        if(isOperand(infix[i]))
            postfix[j++]=infix[i++];
        else if(!isOperand(infix[i]) && st.empty())
            st.push(infix[i++]);
        else{
            if(precedence(infix[i]) > precedence(st.top()))
                st.push(infix[i++]);
            else{
                postfix[j++]=st.top();
                st.pop();
            }
        }
     }

     while(!st.empty()){
        postfix[j++]=st.top();
        st.pop();
     }

     postfix[j]='\0';
     cout<<"Postfix expression : "<<postfix<<endl;

}
