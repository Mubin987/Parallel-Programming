#include <iostream>
#include <omp.h>
#include <ctime>
#define ll long long int
using namespace std;

void Bubblesort(int arr[], ll size) {
    ll i, j, temp;
    bool swapped;
    for (i = 0; i < size - 1; i++) {
        swapped = false;
        #pragma omp parallel for private(j, temp) reduction(||: swapped)
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main3(ll n) {
	int arr[n];
	srand(time(NULL));
//	cout<<"Random numbers array:";
	for(ll i=0;i<n;i++)
	{
		arr[i]=rand()%1000;
//		cout<<arr[i]<<" ";
	}
    
    Bubblesort(arr,n);
//    cout << endl;
//    cout << "Sorted array";
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
    
    return 0;
}

