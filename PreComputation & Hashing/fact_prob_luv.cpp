/*Given T test cases and in each test case a number N.print its facatorial
for each test case %M 
where M=10^9+7

Constraints 
1<= T <= 10^5
1<= N <= 10^5
*/

#include<iostream>
using namespace std;

const int N=1e5+10;
const int M=1e9+7;
long long fact[N];

int main()
{
    fact[0]=1;
    fact[1]=1;
    for(int i=2; i<=N; i++){
        fact[i]=(i * fact[i-1])%M;
    }

    int T=1e5;
    while(T--){
        int n;
        cin>>n;
        cout<<fact[n]<<endl;
    }
}