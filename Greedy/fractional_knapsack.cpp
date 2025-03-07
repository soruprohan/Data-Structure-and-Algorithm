#include<bits/stdc++.h>
using namespace std;

struct Item{
    double value;
    int weight;
};

bool comparator(Item a,Item b)
{
    return (a.value/a.weight > b.value/b.weight);
}

double knapsack(int n,int w,Item *arr)
{
    sort(arr,arr+n,comparator);

    double totalValue=0;
    for(int i=0; i<n; i++){
        if(arr[i].weight <=w){
            totalValue+=arr[i].value;
            w-=arr[i].weight;
        }
        else{
            totalValue+= (arr[i].value/arr[i].weight)*w;
            break;
        }
    }
    return totalValue;
}

int main()
{
    int n,weight;
    cin>>n>>weight;
    Item arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i].value>>arr[i].weight;
    }

    cout<<"The maximum value is "<<knapsack(n,weight,arr);
}
