#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    sort(v.begin(),v.end());
    int wtTime=0,time=0;
    vector<int> anotherway;

    for(int i=0; i<n; i++){
        wtTime+=time;
        time+=v[i];
        anotherway.push_back(time);
    }

    cout<< wtTime/n<<endl;

    int anotherwaysum=0;
    for(int i=0; i<n-1; i++)
        anotherwaysum+=anotherway[i];

    cout<<anotherwaysum/n<<endl;
}
