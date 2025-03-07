#include<bits/stdc++.h>
using namespace std;

void print(vector<int>&v)
{
    for(auto it: v){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cout<<"Size:";
    cin>>n;
    int arr[n];
    vector<int>nge(n,-1);
    stack<int> st;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<2*n; i++){
        if(st.empty())
            st.push(i%n);

        else{
            while(!st.empty() && arr[i%n] > arr[st.top()]){
                nge[st.top()]=arr[i%n];
                st.pop();
            }
            st.push(i%n);
        }
    }
//
//    while(!st.empty()){
//        nge[st.top()]=-1;
//        st.pop();
//    }
    print(nge);

}

