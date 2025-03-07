#include<bits/stdc++.h>

using namespace std;
void printvec(vector<int> v)
{
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(10),v1(10,3);

    v.push_back(n);
    v1.push_back(n);
    printvec(v);
    printvec(v1);

}
