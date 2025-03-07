//https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-the-magical-candy-bags/?update=google&purpose=signup&source=problem-page&fbclid=IwAR2kDiVkEaxu9dkCTCUhzXLuIccNn0Gz3dSfkaSUjlDE6Nb9UHMzt8HNDo4
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,k;
		long long sum=0;
		cin>>n>>k;
		multiset<long long> s;
		for(int i=0; i<n; i++){
			long long x;
			cin>>x;
			s.insert(x);
		}
		for(int i=0; i<k; i++){
			auto it=prev(s.end()); //this is an iterator pointing to the previous iterator of s.end()
			long long var=*it;
			sum+=var;
			s.erase(it);
			long long var2=var/2;
			s.insert(var2);
		}
		cout<<sum<<endl;
	}
}
