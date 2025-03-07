#include<bits/stdc++.h>
using namespace std;

bool rev(string &s,int i,int n)
{
    if(i>=n-i)
        return true;
    if(s[i]!=s[n-i])
        return false;
    else
        return rev(s,i+1,n);
}

int main()
{
    string s;
    cin>>s;
    int n=s.size();
    cout<<rev(s,0,n-1);

}

