
#include <iostream>
#include <ctime>
#define ll long long int
using namespace std;


void BubbleSort(int arr[],ll n)
{
	ll i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}




int main1(ll n)
{
    int arr[n];
    srand(time(NULL));
   // cout << "Random numbers array: ";
    for(ll i = 0; i < n; i++){
        arr[i] = rand() % 1000;
   //     cout << arr[i] << " ";
    }
//   cout << endl;
	n = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr,n);
//	cout << endl;
//	cout << "Sorted array:";
//    for (int i = 0; i < n; i++) 
//	{
//    	cout << arr[i] << " ";
//    }
//   cout << endl;

	return 0;
}


