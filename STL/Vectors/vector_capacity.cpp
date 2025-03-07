#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v;
    cout<<v.size()<<" "<<v.capacity()<<endl;
    v.reserve(100);
     cout<<v.size()<<" "<<v.capacity()<<endl;
     v.push_back(3);
     v.push_back(2);
     cout<<v.size()<<" "<<v.capacity()<<endl;
    v.shrink_to_fit();
      for(int i=0; i<v.size(); i++){cout<<v[i]<<endl;}
       cout<<v.size()<<" "<<v.capacity()<<endl;


}