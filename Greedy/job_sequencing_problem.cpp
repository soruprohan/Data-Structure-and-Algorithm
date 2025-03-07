#include<bits/stdc++.h>
using namespace std;

struct job{
    int id;
    int deadline;
    double profit;
};

bool comparator(job a,job b)
{
    return a.profit>b.profit;
}

pair<int,double> solve(job arr[],int n)
{
    sort(arr,arr+n,comparator);
    double totalProfit=0.0;
    int cnt=0;

    int maxDead=-1;
    for(int i=0; i<n; i++){
        maxDead=max(maxDead,arr[i].deadline);
    }

    int slot[maxDead+1];
    for(int i=0; i<maxDead+1; i++)
        slot[i]=-1;

    for(int i=0; i<n; i++){
        for(int j=arr[i].deadline; j>0; j--){
            if(slot[j]==-1){
                slot[j]=arr[i].id;
                totalProfit+=arr[i].profit;
                cnt++;
                break;
            }
        }
    }
    return {cnt,totalProfit};
}

int main()
{
    int n=4;
    job arr[n]={{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

    pair<int,double> ans=solve(arr,n);

    cout<<"No. of jobs that can be done = "<<ans.first<<endl;
    cout<<"Total profit = "<<ans.second<<endl;
}
