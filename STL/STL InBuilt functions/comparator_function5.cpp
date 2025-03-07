#include<bits/stdc++.h>

using namespace std;

/*Ei Program e amra koyekta pair ke ascending order e sort korbo,kintu pair gulor first element mile gele oi first element er
pair gulo descending order e sort hobe
*/
bool cmp(pair<int,int> a,pair<int,int> b) //This function is called comparator function
{
    if(a.first==b.first)
        return a.second>b.second;
    else
        return a<b;
}

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i].first>>v[i].second;
    }

    sort(v.begin(),v.end(),cmp);

    cout<<"After sorting:"<<endl;
    for(int i=0; i<n; i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
}




