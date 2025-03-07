#include<bits/stdc++.h>
using namespace std;

void print(int *a,int n)
{
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cout<<"Size:";
    cin>>n;
    int arr[n],nge[n];
    stack<int> st;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<n; i++){
        if(st.empty())
            st.push(i);


        else{
            while(!st.empty() && arr[i] > arr[st.top()]){
                nge[st.top()]=arr[i];
                st.pop();
            }

            st.push(i);
        }
    }
    while(!st.empty()){
        nge[st.top()]=-1;
        st.pop();
    }
    //print(arr,n);
    print(nge,n);

}
