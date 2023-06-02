#include <iostream>
#include <pthread.h>
#include <ctime>

using namespace std;

struct merge_sort_params {
    int* arr;
    int l;
    int h;
};
void merges(int arr[],int l,int h,int mid){
	int arrlength=h-l+1;
	int arr1size=mid-l+1;
	int arr2size=h-mid;
	int arrIndex=l;
	int arr1[arr1size],arr2[arr2size];
	for(int i=0;i<arr1size;i++){
			arr1[i]=arr[arrIndex++];
	}
	arrIndex=mid+1;
	for(int i=0;i<arr2size;i++){
			arr2[i]=arr[arrIndex++];
	}
	int i=0,j=0;
	for(int k=l;k<=h;k++){
		if(arr1[i]<arr2[j]&&i<arr1size||j==arr2size){
			arr[k]=arr1[i];
			i++;
		}
		else{
			arr[k]=arr2[j];
			j++;
		}
	}
}
void* merge_sort(void* params) {
    merge_sort_params* p = (merge_sort_params*) params;
    int* arr = p->arr;
    int l = p->l;
    int h = p->h;

    if (l < h) {
        int mid = l + (h - l) / 2;

        pthread_t left_thread;
        merge_sort_params left_params = { arr, l, mid };
        pthread_create(&left_thread, NULL, merge_sort, &left_params);

        pthread_t right_thread;
        merge_sort_params right_params = { arr, mid + 1, h };
        pthread_create(&right_thread, NULL, merge_sort, &right_params);
        
        pthread_join(left_thread, NULL);
        pthread_join(right_thread, NULL);
		merges(arr,l,h,mid);
    }

    pthread_exit(NULL);
}

int main8(int n)
{
    int arr[n];
    srand(time(NULL));
 //   cout << "Random numbers array:";
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
 //       cout << arr[i] << " ";
    }
//   cout << endl;

    pthread_t sort_thread;
    merge_sort_params sort_params = { arr, 0, n - 1 };
    pthread_create(&sort_thread, NULL, merge_sort, &sort_params);
    pthread_join(sort_thread, NULL);

//    cout << "Sorted array:";
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;

    return 0;
}

