#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    getline(cin,s);
    char c;
    cin>>c;
    int ct=count(s.begin(),s.end(),c);

    cout<<ct<<endl;
}
