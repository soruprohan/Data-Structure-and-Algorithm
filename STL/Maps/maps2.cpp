#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<int,int> m;
    m[1]=10;
    m[3]=30;
    m[2];

    map<int,int> :: iterator it;
    for(it=m.begin(); it!=m.end(); it++){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }

    //now lets discuss m.find() function,m.end() function

    auto it2=m.find(3);

    if(it2==m.end())
        cout<<"No key-value pair found"<<endl;
    else{
        cout<<"key  "<<"value"<<endl;
        cout<<it2->first<<"    "<<it2->second<<endl;
    }
}
