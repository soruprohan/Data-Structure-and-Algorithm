#include<bits/stdc++.h>

using namespace std;
void printvector(vector<pair<int,int>> v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
}
int main()
{
    vector<pair<int,int>> v;

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int x,y;
        cin>>x;
        cin>>y;
        v.push_back({x,y});
    }
    printvector(v);
    return 0;
}