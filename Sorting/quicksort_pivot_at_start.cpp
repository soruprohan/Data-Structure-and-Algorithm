#include<iostream>
using namespace std;

int partition(int arr[], int lb, int hb)
{
    int pivot=arr[lb];
    int i=hb+1;

    for(int j=hb; j>=lb; j--){
        if(arr[j]>pivot){
            i--;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[i-1],arr[lb]);
    return i-1;
}

void quickSort(int arr[], int lb, int hb)
{
	if(lb<hb){
        int loc=partition(arr,lb,hb);
        quickSort(arr,lb,loc-1);
        quickSort(arr,loc+1,hb);
	}
}


void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}


int main()
{
	int arr[] = { 7, 6, 10, 5, 9, 2, 1, 15, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}

