#include<iostream>
using namespace std;

class minheap
{
    int arr[100];
    int size=0;
public:
    void insert(int x)
    {
        arr[size]=x;
        int i=size;

        while(i>0 && arr[i]<arr[(i-1)/2]){
            swap(arr[i],arr[(i-1)/2]);
            i=(i-1)/2;
        }
        size++;
    }

    int extractminelement()
    {
        return arr[0];
    }
    void del()
    {
        arr[0]=arr[--size];
        int i=0;
        int j=2*i+1;
        while(j < size-1){
            if(arr[j+1]< arr[j])
                j=j+1;
            if(arr[i] > arr[j]){
                swap(arr[i],arr[j]);
                i=j;
                j=2*i+1;
            }
            else
                break;
        }
    }

    void print()
    {
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};


int main()
{
    minheap ob;
    ob.insert(30);
    ob.insert(20);
    ob.insert(15);
    ob.insert(5);
    ob.insert(10);
    ob.insert(12);
    ob.insert(6);
    ob.print();
    ob.del();
    ob.print();
}
