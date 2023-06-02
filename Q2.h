#include <iostream>
#include <pthread.h>
#include <ctime>
#define ll long long int
using namespace std;

struct ThreadArgs {
    int* arr;
    int low;
    int high;
};


void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}


void* quicksort(void* arg)
{
    ThreadArgs* args = (ThreadArgs*)arg;
    int low = args->low;
    int high = args->high;
    int* arr = args->arr;
    
    int stackSize = high - low + 1;
    int stack[stackSize];
    int top = -1;
    
    stack[++top] = low;
    stack[++top] = high;
    
    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];
        
        int pivotIndex = partition(arr, low, high);
        
        if (pivotIndex - 1 > low) {
            stack[++top] = low;
            stack[++top] = pivotIndex - 1;
        }
        
        if (pivotIndex + 1 < high) {
            stack[++top] = pivotIndex + 1;
            stack[++top] = high;
        }
    }
    
    pthread_exit(NULL);
}

int main5(ll n)
{
	int arr[n];
//	 n = sizeof(arr) / sizeof(arr[0]);
	srand(time(NULL));
//	cout<<"Random numbers array:";
	for(int i=0;i<n;i++)
	{
		arr[i]=rand()%1000;
//		cout<<arr[i]<<" ";
	}
	
    
    
    pthread_t thread;
    ThreadArgs args;
    args.arr = arr;
    args.low = 0;
    args.high = n - 1;
    
    int rc = pthread_create(&thread, NULL, quicksort, (void*)&args);
    if (rc) {
        cout << "Error creating thread; return code: " << rc << endl;
        exit(-1);
    }
    
    pthread_join(thread, NULL);
//    cout << endl;
//    cout << "Sorted array: ";
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
    
    return 0;
}
