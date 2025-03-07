#include<iostream>

using namespace std;


int main()
{
    int graph[100][100]={0};
    int vertices,edges;
    cin>>vertices>>edges;


    for(int i=1; i<=edges; i++){
            int vertex1,vertex2;
            cin>>vertex1>>vertex2;
            graph[vertex1][vertex2]=1;
            graph[vertex2][vertex1]=1;
        }
    
    for(int i=1; i<=vertices; i++){
        for(int j=1; j<=vertices; j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

