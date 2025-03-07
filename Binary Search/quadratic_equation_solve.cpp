#include<bits/stdc++.h>
using namespace std;

int positiveSearch(int a,int b,int c,int start,int end)
{
    int mid=start+(end-start)/2;

    if(a*mid*mid+b*mid+c==0)
        return mid;
    else if(a*mid*mid+b*mid+c>0)
        return firstSearch(a,b,c,)
}

int negativeSearch(int a,int b,int c,int start,int end,int x)
{

}

int main()
{
    int a,b,c;
    cout<<"Enter a, b and c : ";
    cin>>a>>b>>c;

    int x=firstSearch(a,b,c,0,5e8);
}

