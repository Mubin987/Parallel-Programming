#include<iostream>
#include<ctime>
#include<omp.h> // include OpenMP header file
using namespace std;

void merje(int arr[], int l, int h, int mid){
    int arrlength = h - l + 1;
    int arr1size = mid - l + 1;
    int arr2size = h - mid;
    int arrIndex = l;
    int arr1[arr1size], arr2[arr2size];
    
    for(int i = 0; i < arr1size; i++){
        arr1[i] = arr[arrIndex++];
    }
    
    arrIndex = mid + 1;
    for(int i = 0; i < arr2size; i++){
        arr2[i] = arr[arrIndex++];
    }

    int i = 0, j = 0;
    for(int k = l; k <= h; k++){
        if(arr1[i] < arr2[j] && i < arr1size || j == arr2size){
            arr[k] = arr1[i];
            i++;
        }
        else{
            arr[k] = arr2[j];
            j++;
        }
    }
}

void merjesort(int arr[], int l, int h){
    if(l < h){
        int mid = l + (h - l) / 2;
        #pragma omp parallel sections // use OpenMP parallel sections directive
        {
            #pragma omp section // execute the following block of code in parallel
            {
                merjesort(arr, l, mid);
            }

            #pragma omp section // execute the following block of code in parallel
            {
                merjesort(arr, mid + 1, h);
            }
        }
        merje(arr, l, h, mid);
    }
}

int main9(int n) 
{
    int arr[n];
    srand(time(NULL));
 //   cout << "Random numbers array: ";
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 1000;
 //       cout << arr[i] << " ";
    }
//   cout << endl;

    #pragma omp parallel // use OpenMP parallel directive
    {
        #pragma omp single // execute the following block of code once
        {
            merjesort(arr, 0, n - 1);
        }
    }

//    cout << "Sorted array: ";
//    for(int i = 0; i < n; i++){
//        cout << arr[i] << " ";
//    }
//   cout << endl;
}

