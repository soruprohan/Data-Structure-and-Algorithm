#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    getline(cin,s);
    auto it=max_element(s.begin(),s.end());

    cout<<*it<<endl;
}
