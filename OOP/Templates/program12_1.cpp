#include<iostream>
using namespace std;

//This program doesn't work
class vector
{
    int *v;
    int size;
public:
    vector(int n):size(n)
    {
        //v=new int[size];
        for(int i=0; i<3; i++)
            v[i]=0;
    }
    vector(int *arr)
    { 
       // v=new int[size];  
        for(int i=0; i<size; i++)
            v[i]=arr[i];
    }
    ~vector()
    {
        delete[] v;
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
    int arr2[3]={10,20,30}; //3 tai howa lagbe ar vector vec(3) emne declare kora vector gulai use korte hobe naile size pawa jabe na
    
    vec1=vector(arr1); //doesn't work
    vec2=vector(arr2);
    
    int result=vec1*vec2;

    cout<<vec1<<endl;
    cout<<vec2<<endl;
    cout<<result;
}