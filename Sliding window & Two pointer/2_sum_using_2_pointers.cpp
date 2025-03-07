#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v={2,3,5,1,12,6,4};

    int sum;
    cout<<"Enter sum:";
    cin>>sum;

    sort(v.begin(),v.end());
    int left=0;
    int right=v.size()-1;
    int flag=0;

    while(left<right){
       int jogfol=v[left]+v[right];
       if(jogfol==sum){
        flag=1;
        cout<<"YES"<<endl;
        cout<<"Index: "<<left<<" "<<right<<endl;
        break;
       }
       else if(jogfol<sum)
            left++;
       else
            right--;
    }

    if(flag==0)
        cout<<"NO"<<endl;
}

