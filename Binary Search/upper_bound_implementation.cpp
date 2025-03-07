#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &v,int element)
{
    int low=0;
    int high=v.size()-1;

    while(low<high){
        int mid=(low+high)/2;
        if(v[mid] <= element){
            low=mid+1;
        }
        else{               //for(g[mid]>=element)
            high=mid;
        }
    }
    if(v[low]>element){
        return low;
    }

    return -1;
}

int main()
{
    vector<int> v={2,3,3,3,4,6,7,8,9};
    sort(v.begin(),v.end());

    int elem;
    cin>>elem;
    int lb=lowerBound(v,elem);

    cout<<"index: "<<lb<<endl;
    cout<<"and the lower bound is :"<< (lb!= -1? v[lb] : -1)<<endl;
}

