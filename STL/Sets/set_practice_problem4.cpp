//https://www.hackerearth.com/problem/algorithm/monks-birthday-party/?fbclid=IwAR3COuGp9LqoHKWOnfS-duVdKrF0Vx5shbCbGeiWqSgkdoA2z9926vNy5Ew
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		set<string> s;

		for(int i=0; i<n; i++){
			string x;
			cin>>x;
			s.insert(x);
		}
		for(auto &it: s){
			cout<<it<<endl;
		}
	}
}
