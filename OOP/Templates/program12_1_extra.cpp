#include<iostream>
using namespace std;

class vector
{
    int *v;
    int size;
public:
    vector(int n):size(n)
    {
        v=new int[size];
        for(int i=0; i<size; i++)
            v[i]=0;
    }
    vector(int n,int *arr):size(n)
    { 
        v=new int[size];  
        for(int i=0; i<size; i++)
            v[i]=arr[i];
    }
    int operator*(vector &arr)
    {
        int sum=0;
        for(int i=0; i<size; i++){
            sum+=this->v[i] * arr.v[i];
        }
        return sum;
    }
    friend ostream& operator<<(ostream& , vector&);
    
};

ostream& operator<<(ostream& COUT, vector &ob)
{
    for(int i=0; i<ob.size; i++){
        COUT<< ob.v[i]<<" ";
    }
    return COUT;
}

int main()
{
    vector vec1(3); //null vector declared
    vector vec2(3);

    cout<<vec1<<endl;
    
    int arr1[3]={1,2,3};
    int arr2[3]={10,20,30}; 
    
    vector vec3(3,arr1); 
    vector vec4(3,arr2);
    
    int result=vec3*vec4;
    cout<<vec3<<endl;
    cout<<vec4<<endl;
    cout<<result;
}