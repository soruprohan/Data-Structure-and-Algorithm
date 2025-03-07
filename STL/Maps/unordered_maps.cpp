#include<bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<int,string> m;
    m[0]="cse";
    m[3]="eee";
    m[2]="bme";
    m[69]="ece";
    m[15]="ok bhai";

    for(auto value :m){
        cout<<value.first<<" "<<value.second<<endl;
    }
}