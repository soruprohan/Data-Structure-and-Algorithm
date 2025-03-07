/*given N strings print unique strings in lexicographical order
with their freequency
N<=10^5
|S|<=100
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
    map<string,int> m;

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        m[s]=m[s]+1;
    }
    cout<<endl;
    for(auto value: m){
        cout<<value.first<<" "<<value.second<<endl;
    }
}
