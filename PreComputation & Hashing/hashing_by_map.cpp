#include<iostream>
#include<map>
using namespace std;

int main()
{
    string s;
    cout<<"Enter s:";
    cin>>s;

    //pre computing
    map<char,int> mpp;
    for(int i=0; i<s.size(); i++){
        mpp[s[i]]++;
    }

    int q;
    cout<<"Enter q:";
    cin>>q;

    while(q--){
        char c;
        cout<<"Enter c:";
        cin>>c;
        cout<<mpp[c]<<endl;
    }
}


