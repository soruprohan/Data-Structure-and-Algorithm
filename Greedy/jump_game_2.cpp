#include<bits/stdc++.h>
using namespace std;

int jumps(vector<int> &v)
{
    int n=v.size();
    int jumpCnt=0,l=0,r=0;

    while(r<n-1){
        int farthest=0;
        for(int i=l; i<=r; i++){
            farthest=max(farthest,i+v[i]);
        }
        l=r+1;
        r=farthest;
        jumpCnt++;
    }

    return jumpCnt;
}

int main()
{
    vector<int> v={2,3,1,4,1,1,1,2};
    cout<<jumps(v);
}
