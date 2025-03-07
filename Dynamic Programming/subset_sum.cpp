#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];

    //leetcode version of the problem,here target sum will not be given,but know that it will be half of array sum
    int sum=accumulate(arr.begin(),arr.end(),0) /2;

    cout<<func(n-1,arr,);
}