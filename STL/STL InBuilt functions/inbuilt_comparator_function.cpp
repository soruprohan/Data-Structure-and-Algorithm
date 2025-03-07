#include<bits/stdc++.h>

using namespace std;

/*Ei Program e amra koyekta pair ke ascending order e sort korbo,kintu pair gulor first element mile gele oi first element er
pair gulo descending order e sort hobe,and eijonne amra inbuilt sort function+comparator function use korbo
*/
bool cmp(pair<int,int> a,pair<int,int> b) //This function is called comparator function
{
    if(a.first==b.first){
        if(a.second<b.second)
            return true;
        else
            return false;
    }

    else if(a>b)
        return true;
    else
        return false;


}
using namespace std;

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

