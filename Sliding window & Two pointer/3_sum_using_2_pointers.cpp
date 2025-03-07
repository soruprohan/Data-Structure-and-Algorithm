#include<bits/stdc++.h>
using namespace std;

//given an array ,you need to return the unique triplets that has a sum of zero

vector<vector<int>> func(vector<int> &v)
{
    vector<vector<int>> ans;
    sort(v.begin(),v.end());

    for(int i=0; i<v.size(); i++){
        if(i>0 && v[i]==v[i-1]) continue;

        int j=i+1;
        int k=v.size()-1;
        while(j<k){
            int sum=v[i]+v[j]+v[k];
            if(sum < 0)
                j++;
            else if(sum > 0)
                k--;
            else{
                ans.push_back({v[i],v[j],v[k]});
                j++;
                k--;
                while(j<k && v[j]==v[j-1]) j++;
                while(j<k && v[k]==v[k+1]) k--;
            }
        }
    }

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
