//https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/monk-and-his-friends/?fbclid=IwAR1n1FJUNpWIeq7dHY-HytoqqE1nbK9gD4jMjI2UWGTPE8GF4kHROCb7ouA
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin>>q;
    while(q--){
        multiset<long long> s;
        int n,m;
        cin>>n>>m;
        for(int i=0; i<n; i++){
            long long x;
            cin>>x;
            s.insert(x);
        }
        for(int i=0; i<m; i++){
            long long x;
            cin>>x;
            auto it=s.find(x);
            if(it!=s.end())
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
            s.insert(x);
        }
    }
}

