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
        for(int j=1; j<=n; j++){
            if(gm[i][j]==1){
                gl[i].push_back(j);
            }
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    int gm[100][100]={0};               //function e pathanor jonno const use kora hoise,n+1 use na kore,2nd parameter er ekdom hubhu mil thakte hobe,100 thakle
                                    //function parameter eo 100 likhte hobe,10,20 likhle hobe na
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        gm[x][y]=1;
        gm[y][x]=1;
    }

    vector<int>gl[n+1];

    print_matrix(gm,n);
    convert(gm,gl,n);
    print_list(gl,n);

}
