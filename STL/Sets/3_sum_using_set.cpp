#include<bits/stdc++.h>
using namespace std;

//given an array ,you need to return the unique triplets that has a sum of zero

vector<vector<int>> func(vector<int> &v)
{
    set<vector<int>> st;

    for(int i=0; i<v.size(); i++){
        set<int> hashset;
        for(int j=i+1; j<v.size(); j++){
            int third= -(v[i]+v[j]);
            if(hashset.find(third)!=hashset.end()){
                vector<int> temp={v[i],v[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashset.insert(v[j]);
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

int main()
{
    vector<int> v({-2,-2,-2,-1,-1,0,0,0,2,2,2,2});

    vector<vector<int>> ans=func(v);

    for(auto it: ans){
        for(auto it2: it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
}

