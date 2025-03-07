/*this method is wrong for 0/1 knapsack problem
Greedy approach like this works only for fractional knapsack problem
for 0/1 knapsack problem we have to use dp,or backtracking or branch and bound

consider the example n=4,maxwt=8
values={2,5,3,1}
weights={20,30,12,2}

this method will give 50 but the correct answer is 52
*/
#include<bits/stdc++.h>
using namespace std;

struct Item
{
    double value;
    int weight;
};

bool comparator(Item a,Item b)
{
    return ((double)(a.value/a.weight) > (double)(b.value/b.weight));
}

double knapsack(Item *arr,int n,int maxWt)
{
    sort(arr,arr+n,comparator);
    double totalValue=0;

    for(int i=0; i<n; i++){
        if(arr[i].weight<=maxWt){
            totalValue+=arr[i].value;
            maxWt-=arr[i].weight;
        }
        else{
            break;
        }
    }
    return totalValue;
}

int main()
{
    int n,maxWt;
    cin>>n>>maxWt;
    Item arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i].value>>arr[i].weight;
    }

    cout<<"maximum value= "<<knapsack(arr,n,maxWt);
}
