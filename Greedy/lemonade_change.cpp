#include<bits/stdc++.h>
using namespace std;

bool lemon(vector<int>&v,int n)
{
    int five=0,ten=0;
    for(int i=0; i<n; i++){
        if(v[i]==5)
        five++;
        else if(v[i]==10){
            if(five){
                ten++;
                five--;
            }
            else
                return false;
        }
        else{
            if(ten && five){
                ten--;
                five--;
            }
            else if(five>=3){
                five=five-3;
            }
            else
                return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    cout<<lemon(v,n);
}
