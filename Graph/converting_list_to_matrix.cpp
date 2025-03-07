#include<iostream>
#include<vector>
using namespace std;

void print_matrix(int g[][100],int n)       //c++ e 2d array as a function er parameter hisebe const ba const variable chara kisu use kora jay na
{
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
}

void print_list(vector<int> g[],int n)
{
    for(int i=1; i<=n; i++){
            cout<<i<<"->";
        for(int j=0; j<g[i].size(); j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
}

void convert(int gm[][100],vector<int>gl[],int n)
{
    for(int i=1; i<=n; i++){
        for(int j=0; j<gl[i].size(); j++){
                int x;
                x=gl[i][j];
                gm[i][x]=1;
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    int gm[100][100]={0};               //function e pathanor jonno const use kora hoise,n+1 use na kore,2nd parameter er ekdom hubhu mil thakte hobe,100 thakle
                                //function parameter eo 100 likhte hobe,10,20 likhle hobe na
    vector<int>gl[n+1];
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        if(x!=y){
            gl[x].push_back(y);
            gl[y].push_back(x);
        }
        else{
            gl[x].push_back(y);
        }
    }

    print_list(gl,n);

    convert(gm,gl,n);

    print_matrix(gm,n);
}
