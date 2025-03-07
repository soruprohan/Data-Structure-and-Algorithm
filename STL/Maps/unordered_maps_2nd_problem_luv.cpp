#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main()
{
    int n;
    cin>>n;

    unordered_map<string,int> m;
    while(n--){
        string s;
        cin>>s;

        m[s]++;
    }
    int q;
    cout<<"Enter queries:";
    cin>>q;

    while(q--){
        string s;
        cin>>s;
        cout<<m[s]<<endl;
    }
}
