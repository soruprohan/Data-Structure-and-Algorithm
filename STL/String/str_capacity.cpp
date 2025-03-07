#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cout<<s.length()<<" "<<s.size()<<" "<<s.capacity()<<endl;
    s="hellohellohellohello";
    cout<<s.length()<<" "<<s.size()<<" "<<s.capacity()<<endl;
    s.shrink_to_fit();
    cout<<s.length()<<" "<<s.size()<<" "<<s.capacity()<<endl;
    s.reserve(109);
    cout<<s.length()<<" "<<s.size()<<" "<<s.capacity()<<endl;
    s.reserve();
    cout<<s.length()<<" "<<s.size()<<" "<<s.capacity()<<endl;
    s.reserve(10);
    cout<<s.length()<<" "<<s.size()<<" "<<s.capacity()<<endl;
}