#include<iostream>
#include <fstream>
#include "B1.h"
#include "B2.h"
#include "B3.h"
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"
#include "M1.h"
#include "M2.h"
#include "M3.h"
#include <ctime>
using namespace std;
void compare_bs();
void compare_qs();
void compare_ms();
void inputsizes(long long int arr[],int n);
void drawgraph(long long int arr[],double time[],int n); 
clock_t treq;

int main()
{
	system("COLOR F1");
	int choice;
	cout<<"------ Serial v/s Pthread v/s OpenMP ------\n"<<endl;
	cout<<"1. Bubble Sort"<<endl;
	cout<<"2. Quick Sort"<<endl;
	cout<<"3. Merge Sort"<<endl;
	cout<<"4. None"<<endl<<endl;
	do{
		cout<<"\nWhich algorithm you want to compare(enter correct option):";
		cin>>choice;
		while(choice!=1&&choice!=2&&choice!=3&&choice!=4){
			cout<<"Enter correct option:";
			cin>>choice;
		}
		if(choice==1){
			compare_bs();
		}
		else if(choice==2){
			compare_qs();
		}
		else if(choice==3){
			compare_ms();
		}
	}while(choice!=4);
	return 0;
}

void inputsizes(long long int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<"Array "<<i+1<<" length: ";
		cin>>arr[i];
	}
}

void drawgraph(long long int arr[],double time[],int n){
	cout<<endl;
	ofstream outfile;
	outfile.open("data.csv");
	outfile<<"Array Size"<<","<<"Serial"<<","<<"pthread"<<","<<"openMP"<<endl;	
	for(int i=0;i<n;i++){
		outfile<<arr[i]<<","<<time[i]<<","<<time[i+n]<<","<<time[i+(2*n)]<<endl;
		cout<<"Arr Length:"<<arr[i]<<"\t";
		cout<<"Time:"<<time[i]<<","<<time[i+n]<<","<<time[i+(2*n)]<<endl;
	}
	outfile.close();
	cout<<endl;
}

void compare_bs(){
	int n;
	cout<<"Enter number of arrays you want Graph for: ";
	cin>>n;
	long long int arr[n];
	inputsizes(arr,n);
	
	double time_serial[n];
	for(int i=0;i<n;i++){
		treq= clock();
		main1(arr[i]);
		treq = clock() - treq;
		time_serial[i]=(double)treq/CLOCKS_PER_SEC;
	}
	//cout<<"\nBubble Sort Serial"<<endl;
	//drawgraph(arr,time_serial,n);
	
	double time_pthread[n];
	for(int i=0;i<n;i++){
		treq= clock();
		main2(arr[i]);
		treq = clock() - treq;
		time_pthread[i]=(double)treq/CLOCKS_PER_SEC;
	}
	//cout<<"\nBubble Sort pthread"<<endl;
	//drawgraph(arr,time_pthread,n);
	
	double time_openMP[n];
	for(int i=0;i<n;i++){
		treq= clock();
		main3(arr[i]);
		treq = clock() - treq;
		time_openMP[i]=(double)treq/CLOCKS_PER_SEC;
	}
	//cout<<"\nBubble Sort OpenMP"<<endl;
	//drawgraph(arr,time_openMP,n);
	
	double time_bubble[n+n+n];
	for(int i=0;i<n;i++){
		time_bubble[i]=time_serial[i];
		time_bubble[i+n]=time_pthread[i];
		time_bubble[i+(2*n)]=time_openMP[i];
	}
	drawgraph(arr,time_bubble,n);
	
}

void compare_qs(){
	int n;
	cout<<"Enter number of arrays you want Graph for: ";
	cin>>n;
	long long int arr[n];
	inputsizes(arr,n);
	
	double time_serial[n];
	for(int i=0;i<n;i++){
		treq= clock();
		main4(arr[i]);
		treq = clock() - treq;
		time_serial[i]=(double)treq/CLOCKS_PER_SEC;
	}
//	cout<<"\nQuick Sort Serial"<<endl;
//	drawgraph(arr,time_serial,n);
	
	double time_pthread[n];
	for(int i=0;i<n;i++){
		treq= clock();
		main5(arr[i]);
		treq = clock() - treq;
		time_pthread[i]=(double)treq/CLOCKS_PER_SEC;
	}
//	cout<<"\nQuick Sort pthread"<<endl;
//	drawgraph(arr,time_pthread,n);
	
	double time_openMP[n];
	for(int i=0;i<n;i++){
		treq= clock();
		main6(arr[i]);
		treq = clock() - treq;
		time_openMP[i]=(double)treq/CLOCKS_PER_SEC;
	}
//	cout<<"\nQuick Sort OpenMP"<<endl;
//	drawgraph(arr,time_openMP,n);
	
	double time_quick[n+n+n];
	for(int i=0;i<n;i++){
		time_quick[i]=time_serial[i];
		time_quick[i+n]=time_pthread[i];
		time_quick[i+(2*n)]=time_openMP[i];
	}
	drawgraph(arr,time_quick,n);
	
}

void compare_ms(){
	int n;
	cout<<"Enter number of arrays you want Graph for: ";
	cin>>n;
	long long int arr[n];
	inputsizes(arr,n);
	
	double time_serial[n];
	for(int i=0;i<n;i++){
		treq= clock();
		main7(arr[i]);
		treq = clock() - treq;
		time_serial[i]=(double)treq/CLOCKS_PER_SEC;
	}
//	cout<<"\nMerge Sort Serial"<<endl;
//	drawgraph(arr,time_serial,n);
	
	double time_pthread[n];
	for(int i=0;i<n;i++){
		treq= clock();
		main8(arr[i]);
		treq = clock() - treq;
		time_pthread[i]=(double)treq/CLOCKS_PER_SEC;
	}
//	cout<<"\nMerge Sort pthread"<<endl;
//	drawgraph(arr,time_pthread,n);
	
	double time_openMP[n];
	for(int i=0;i<n;i++){
		treq= clock();
		main9(arr[i]);
		treq = clock() - treq;
		time_openMP[i]=(double)treq/CLOCKS_PER_SEC;
	}
//	cout<<"\nMerge Sort OpenMP"<<endl;
//	drawgraph(arr,time_openMP,n);
	
	double time_merge[n+n+n];
	for(int i=0;i<n;i++){
		time_merge[i]=time_serial[i];
		time_merge[i+n]=time_pthread[i];
		time_merge[i+(2*n)]=time_openMP[i];
	}
	drawgraph(arr,time_merge,n);
	
}












