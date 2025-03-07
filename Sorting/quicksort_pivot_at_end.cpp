#include<iostream>
#include<algorithm>
#include<chrono>
#include<cstdlib>
#include<ctime>
using namespace std;

//this function partitions the array into two parts
int partition(int arr[], int lb, int hb)
{
    int pivot=arr[hb];  //the end element is chosen as pivot
	int i=lb-1;

	for(int j=lb; j<=hb; j++){
        if(arr[j]<pivot){       //if current element is smaller than pivot
            i++;                //increment index of smaller element then swap
            swap(arr[i],arr[j]);
        }
	}
	swap(arr[i+1],arr[hb]);
	return i+1;
}

void quickSort(int arr[], int lb, int hb)
{
	if(lb<hb){
        int loc=partition(arr,lb,hb);   //loc is the partition return address
        quickSort(arr,lb,loc-1);        //recursive calls to quicksort makes sure
        quickSort(arr,loc+1,hb);        //smaller element than pivot goes left and higher element goes right
	}
}

// generating random array
void random(int *arr,int n)
{
    for(int i=0; i<n; i++)
    {
        arr[i]=rand()%5000; //random numbers generated between 0 to 5000 which will be the elements of the array
    }
}

int main()
{
    srand(time(NULL));
    int input[6]= {1000, 5000, 10000 , 25000, 50000, 75000}; //this array only contains the sizes of the arrays to be sorted

    //measuring the execution time of arrays with different inputs
    for(int i=0; i<6; i++)
    {
        int n=input[i]; //now n is size at each iteration

        int arr[n];
        random(arr,n);

        auto begin=chrono::high_resolution_clock::now(); // Starts counting cycles

        quickSort(arr,0,n);

        auto end=chrono::high_resolution_clock::now(); // Ends counting cycles


        // Calculates duration in milliseconds
        auto duration=chrono::duration_cast<chrono::milliseconds>(end-begin).count();
        cout<<n<<" elements sorted in:  "<< duration<< "  milliseconds."<<endl;
    }

    return 0;
}

