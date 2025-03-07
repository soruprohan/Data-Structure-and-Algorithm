#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cout<<"Enter a string to sort its charatcers:"<<endl;
    getline(cin,s);
    sort(s.begin(),s.end());
    cout<<s<<endl;

    int n;
    cout<<"Enter number of indivual strings that you want to sort:  ";
    cin>>n;
    cin.ignore();

    vector<string> v;
    for(int i=0; i<n; i++){
        string s;
        getline(cin,s);
        v.push_back(s);
    }
    sort(v.begin(),v.end());

    for(auto &value :v){
        cout<<value<<endl;
    }

}
