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
    int N;
    cin>>N;
    vector<int> v[N];
    for(int i=0; i<N; i++){
        int n;
        cin>>n;
        for(int j=0; j<n; j++){
            int x;
            cin>>x;
            v[i].push_back(x);
        }
        //printvec(v[i]); etao kaj kore ,just protibar ekta kore vector input er por ota output show kore.sob ekbare na kore

    }
    for(int i=0; i<N; i++){
        printvec(v[i]);
    }
}
