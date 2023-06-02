#include <iostream>
#include <omp.h>
#include <ctime>
#define ll long long int
using namespace std;

void swaped(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int div(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swaped(&arr[i], &arr[j]);
        }
    }
    swaped(&arr[i + 1], &arr[high]);
    return i + 1;
}


void quicksort(int arr[], int low, int high)
{
    if (low < high) {
        int pivotIndex = div(arr, low, high);

        #pragma omp parallel sections
        {
            #pragma omp section
            {
                quicksort(arr, low, pivotIndex - 1);
            }

            #pragma omp section
            {
                quicksort(arr, pivotIndex + 1, high);
            }
        }
    }
}

int main6(ll n)
{
	int arr[n];
	srand(time(NULL));
//	n = sizeof(arr) / sizeof(arr[0]);
//	cout<<"Random numbers array:";
	for(int i=0;i<n;i++)
	{
		arr[i]=rand()%1000;
//		cout<<arr[i]<<" ";
	}
    #pragma omp parallel
    {
        #pragma omp single
        quicksort(arr, 0, n - 1);
    }
	
//	cout << endl;
//    cout << "Sorted array: ";
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;

    return 0;
}
