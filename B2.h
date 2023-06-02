#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <ctime>
#define ll long long int
using namespace std;
const int NUM_THREADS = 2;

typedef struct {
    int *threadId;
    long long int n;
    int *arr;
} ThreadParams;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void* bubbleSort(void* arg) {
    ThreadParams* params = (ThreadParams*)arg;
    int* threadId = params->threadId;
    long long int n = params->n;
    int* arr = params->arr;
    int start, end;

    if (*threadId == 0) {
        start = 0;
        end = n - 1;
    } else {
        start = 1;
        end = n - 1;
    }

    for (int i = start; i < end; i += 2) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }

    pthread_exit(NULL);
}

void oddEvenBubbleSort(int arr[], ll n) {
    bool isSorted = false;
    pthread_t threads[NUM_THREADS];
    ThreadParams params[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        params[i].threadId = new int(i);
        params[i].arr = arr;
        params[i].n = n;
    }
    while (!isSorted) {
        isSorted = true;

        for (int i = 0; i < NUM_THREADS; i++) {
            pthread_create(&threads[i], NULL, bubbleSort, (void*)&params[i]);
        }

        for (int i = 0; i < NUM_THREADS; i++) {
            pthread_join(threads[i], NULL);
        }

        for (int i = 0; i < n - 1; i += 2) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }
    }
}

int main2(ll n) {
    srand(time(NULL));
    int arr[n];
   // cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
   //     cout << arr[i] << " ";
    }
   // cout << endl;

    oddEvenBubbleSort(arr, n);

//    cout << "Sorted array: ";
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
}


