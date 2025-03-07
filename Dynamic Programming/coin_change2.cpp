#include<bits/stdc++.h>
using namespace std;

vector<int> dp(10010,-1);

int func(int amount,vector<int> &coins,int &ct)
{
    if(amount==0) {
        return 1;
    }
    for(int coin:coins){
        if(amount-coin>=0)
            func(amount-coin,coins,ct);
    }
    return;
}

int coinChange(vector<int> &coins,int amount)
{
    func(amount,coins,ct);
    return ct;
}
int main()
{
    vector<int> coins={1,2,5};
    cout<<coinChange(coins,5);
}