#include<bits/stdc++.h>

using namespace std;

int main()
{
    multimap<int,string> m;

    m.insert({7,"civil"});
    m.insert({7,"cse"});
    m.insert({3,"eee"});
    m.insert({9,"ece"});
    m.insert({4,"mse"});
    m.insert({2,"mse"});

    for(auto value:m)
    {
        cout<<value.first<<" "<<value.second<<endl;
    }
}
