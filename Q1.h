#include <iostream>
#include <stack>
#include <ctime>
#define ll long long int
using namespace std;

void swapp(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int division(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swapp(&arr[i], &arr[j]);
        }
    }
    swapp(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void iterativeQuickSort(int arr[], int low, int high) {
    stack<int> stack;
  
    stack.push(low);
    stack.push(high);
  
    while (!stack.empty()) {
        high = stack.top();
        stack.pop();
        low = stack.top();
        stack.pop();
  
        int pivot = division(arr, low, high);
  
        if (pivot - 1 > low) {
            stack.push(low);
            stack.push(pivot - 1);
        }
  
        if (pivot + 1 < high) {
            stack.push(pivot + 1);
            stack.push(high);
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main4(ll n) {
	int arr[n];
	srand(time(NULL));
//	cout<<"Random numbers array:";
	for(int i=0;i<n;i++)
	{
		arr[i]=rand()%1000;
//		cout<<arr[i]<<" ";
	}
//     n = sizeof(arr) / sizeof(arr[0]);
  
    iterativeQuickSort(arr, 0, n - 1);
 //   cout << "Sorted array: \n";
 //   printArray(arr, n);
    return 0;
}

