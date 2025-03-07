#include<iostream>
using namespace std;

template<class T>
class vector
{
    T *v;
    int size;
public:
    vector(int n):size(n)
    {
        v=new T[size];
        for(int i=0; i<size; i++)
            v[i]=0;
    }
    vector(int n,int *arr):size(n)
    { 
        v=new T[size];  
        for(int i=0; i<size; i++)
            v[i]=arr[i];
    }
    ~vector()
    {
        delete[] v;
        cout<<"Destructor called"<<endl;
    }
    T operator*(vector &arr)
    {
        T sum=0;
        for(int i=0; i<size; i++){
            sum+=this->v[i] * arr.v[i];
        }
        return sum;
    }
    friend ostream& operator<<(ostream& , vector<int>&);
    
};

ostream& operator<<(ostream& COUT, vector<int> &ob)
{
    for(int i=0; i<ob.size; i++){
        COUT<< ob.v[i]<<" ";
    }
    return COUT;
}

int main()
{
    vector<int>vec1(3); //null vector declared
    vector<int>vec2(3);

    cout<<vec1<<endl;
    
    int arr1[3]={1,2,3};
    int arr2[3]={10,20,30}; 
    
    vector<int>vec3(3,arr1); 
    vector<int>vec4(3,arr2);
    
    int result=vec3*vec4;
    cout<<vec3<<endl;
    cout<<vec4<<endl;
    cout<<result;
}