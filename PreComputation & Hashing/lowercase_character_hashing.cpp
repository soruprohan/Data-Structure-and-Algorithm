#include<iostream>
using namespace std;

int main()
{
    int hash[26]={0};
    string s;
    cout<<"Enter s:";
    cin>>s;

    //pre computing
    for(int i=0; i<s.size(); i++){
        hash[s[i]-'a']++;
    }

    int q;
    cout<<"Enter q:";
    cin>>q;

    while(q--){
        char c;
        cout<<"Enter c:";
        cin>>c;
        cout<<hash[c-'a']<<endl;
    }
}
