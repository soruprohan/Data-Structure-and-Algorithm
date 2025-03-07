#include<iostream>
using namespace std;

template<class T>
class Vector
{
    int s;
    int c;
    T *arr;
public:
    Vector()
    {
        s=c=0;
        arr= new int[0];
    }

    Vector(int x)
    {
        s=x;
        c=x+5;
        arr=new T[c];
        for(int i=0; i<s; i++){
            arr[i]=0;
        }
    }

    Vector(int x,int y)
    {
        s=x;
        c=x+5;
        arr=new T[c];
        for(int i=0; i<s; i++){
            arr[i]=y;
        }
    }

    Vector(const Vector& rhs)
    {
        s=rhs.s;
        c=rhs.c;
        arr=new T[c];
        for(int i=0; i<s; i++)
        {
            arr[i]=rhs.arr[i];
        }
    }

    ~Vector()
    {
        delete []arr;
    }
    int size(){return s;}
    int capacity(){return c;}
    bool empty(){return size==0;}
    void pushback(T value)
    {
        if(s<c){
        arr[s]=value;
        s++;
        }
        else{
            c=c*2;
            T *newArray=new T[c];
            for(int i=0; i<c; i++){
                newArray[i]=arr[i];
            }
            newArray[s]=value;
            s++;
            delete[] arr;
            arr=newArray;   //This is a pointer,not an whole array
        }
    }

    void popback()
    {
        if(s==0)
            return;
        else
            s--;
    }
     T& Front()
    {
        return arr[0];
    }

    T& Back()
    {
        return arr[s-1];
    }
     void Insert(int index, T value)
     {
         if(index<0 || index>=s){
             cout<<"Invalid index"<<endl;
             return;
         }
         if(s!=c){
             s++;
             for(int i=s; i>index; i--){
                arr[i]=arr[i-1];
             }
             arr[index]=value;
         }
         else{
            c=c*2;
            T *newArray= new T[c];
            for(int i=0; i<s; i++){
                newArray[i]=arr[i];
            }
            delete[] arr;
            arr=newArray;
            Insert(index, value);
         }
     }
     void Clear()
     {
         s=0;
     }
     void Erase(int index)
     {
          if(index<0 || index>=s){
             cout<<"Invalid index"<<endl;
             return;
         }

         for(int i=index; i<s; i++){
            arr[i]=arr[i+1];
         }
         s--;
     }
    bool operator==(Vector &rhs)
    {
        if(size()!=rhs.size())
        {
            return false;
        }
        else
        {
           for(int i=0; i<size(); i++){
            if(arr[i]!=rhs.arr[i])
                return false;
           }
        }
        return true;
    }

    bool operator!=(Vector &ob)
    {
        return !(*this == ob);
    }

    T& operator[](int i)
    {
        return arr[i];
    }

    friend ostream& operator<<(ostream &COUT,Vector &ob)
    {
        for(int i=0; i<ob.s; i++){
            COUT<<ob.arr[i]<<" ";
        }
        COUT<<" || ";

        for(int i=ob.s; i<ob.c; i++){
            COUT<<ob.arr[i]<<" ";
        }
        COUT<<endl;
        return COUT;

    }

    void printvector()
    {
        for(int i=0; i<s; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

int main()
{
    Vector<int> v(3);
    Vector<int> w(v);
    v.pushback(69);
    v.pushback(69);
    v.printvector();
    v.Insert(2,4);
    v.printvector();

}
