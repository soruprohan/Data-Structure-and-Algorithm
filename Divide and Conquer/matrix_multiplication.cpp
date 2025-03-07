#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> multiplication(vector<vector<int>> &a,vector<vector<int>> &b)
{
    int n=a.size();
    int m=a[0].size();

    int p=b.size();
    int q=b[0].size();

    if(m!=p){
        cout<<"matrix multiplication not possible.Incorrect dimensions"<<endl;
        exit(0);
    }

    vector<vector<int>> c(n,vector<int>(q,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<q; j++){
            for(int k=0; k<m; k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    return c;
}

void print(vector<vector<int>> &v)
{
    cout<<"resultant matrix:"<<endl;
    for(auto it:v){
        for(auto it2:it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
}

vector<vector<int>> input()
{
    cout<<"row column no:";
     int n,m;
     cin>>n>>m;
     vector<vector<int>>matrix(n,vector<int>(m));
     cout<<"matrix elements:"<<endl;
     for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>matrix[i][j];
        }
    }
    return matrix;
}

int main()
{
    vector<vector<int>> matrix1=input();
    vector<vector<int>> matrix2=input();
    vector<vector<int>> matrix3=multiplication(matrix1,matrix2);
    print(matrix3);
}
