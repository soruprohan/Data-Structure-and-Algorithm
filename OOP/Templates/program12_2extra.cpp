#include<iostream>
using namespace std;
//This program doesn't work 
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
    vector(int *arr)
    {  
        for(int i=0; i<size; i++)
            v[i]=arr[i];
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

ostream& operator<<(ostream& COUT, vector<int> &ob) //sobsomoy int a hoile lav ki hoilo
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
    
    vec1=arr1; 
    vec2=arr2;
    
    int result=vec1*vec2;
    cout<<vec1<<endl;
    cout<<vec2<<endl;
    cout<<result;
}