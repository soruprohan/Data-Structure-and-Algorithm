#include<bits/stdc++.h>

using namespace std;

/*Ei Program e amra koyekta pair ke ascending order e sort korbo,kintu pair gulor first element mile gele oi first element er
pair gulo descending order e sort hobe
*/
bool check(pair<int,int> a,pair<int,int> b) //This function is called comparator function
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

//This is the same function,this also works
//bool check2(pair<int,int> a,pair<int,int> b)
//{
//    if(a.first==b.first)
//        return (a.second<b.second);
//
//    return (a.first>b.first);
//}

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i].first>>v[i].second;
    }


    for(int i=0; i<n-1; i++){
        int flag=0;
        for(int j=0; j<n-1-i; j++){
            if(check(v[j],v[j+1])){
               swap(v[j],v[j+1]);
               flag=1;
            }
        }
        if(flag==0)
            break;
    }

    cout<<"After sorting:"<<endl;
    for(int i=0; i<n; i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
}

