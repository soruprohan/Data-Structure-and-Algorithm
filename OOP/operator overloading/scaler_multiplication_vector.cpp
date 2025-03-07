#include<iostream>
using namespace std;

class vector
{
    int v[3];
public:
    vector();
    vector(int *ptr);
    friend vector operator*(int ,vector &);
    friend vector operator*(vector &,int );
    friend istream& operator>>(istream &,vector &);
    friend ostream& operator<<(ostream &,vector &);
};

vector :: vector()
{
    for(int i=0; i<3; i++){
        v[i]=0;
    }
}
vector :: vector(int *ptr)
{
    for(int i=0; i<3; i++){
        v[i]=ptr[i];
    }
}
vector operator*(int a,vector &vec)
{
    vector temp;
    for(int i=0; i<3; i++){
        temp.v[i]=a * vec.v[i];
    }
    return temp;
}
vector operator *(vector &vec,int a)
{
    vector temp;
    for(int i=0; i<3; i++){
        temp.v[i]=a* vec.v[i];
    }
    return temp;
}
istream& operator>>(istream &CIN,vector &vec)
{
    for(int i=0; i<3; i++){
        CIN>>vec.v[i];
    }
    return(CIN);
}
ostream& operator<<(ostream &COUT,vector &vec)
{
    COUT<<"("<<vec.v[0];
    for(int i=1; i<3; i++){
        COUT<<","<<vec.v[i];
    }
    COUT<<")";

    return (COUT);
}

int main()
{
    int arr[3]={10,20,40};
    vector v=arr; //parameterized constructor e object v te array er address pathailam

    vector v2;
    v2=3*v;
    cout<<v<<v2;

    //Time to test the input stream function for vector
    vector v1;
    cout<<"Enter three values for vector:"<<endl;
    cin>>v1;
    cout<<v1;
}

