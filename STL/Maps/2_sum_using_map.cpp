#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v={2,3,5,1,12,6,4};

    int sum;
    cout<<"Enter sum:";
    cin>>sum;

    map<int,int> mp;
    int flag=0;

    for(int i=0; i<v.size(); i++){
        int a=v[i];
        int more=sum-a;

        if(mp.find(more)!= mp.end()){
            cout<<"YES"<<endl;
            cout<<"Index: "<<mp[more]<<" "<<i<<endl;
            flag=1;
            break;
        }
        mp[a]=i;
    }

    if(flag==0)
        cout<<"NO"<<endl;
}
