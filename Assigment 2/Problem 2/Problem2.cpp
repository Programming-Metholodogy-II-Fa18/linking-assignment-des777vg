#include<iostream>
#include <cmath>
#include <string>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << A[i] << ",";
	printf("\n");
}
void merge(int arr[], int l, int m, int r)
{

	//cout << "l: " << l << " m: " << m << " r: " << r << endl;
	//printArray(arr, 11);
	//cout << endl;
	

	
	if (arr[m] < arr[m + 1]) {
		return;
	}

	int  a = l; // create temp variable pointing at first element in first half
	 int b = m + 1; // create temp variable pointing at first element in second half
	while (a < b && b <= r) { // while everyting still w/in bounds
		//	printArray(arr, sizeof(arr) / sizeof(arr[0]));
		if (arr[a] > arr[b]) { // if l > r, then push everything down, and insert
			int temp = arr[b];
			for (int i = b; i >= a; i--) {
				arr[i] = arr[i - 1];
			}
			arr[a] = temp;
			a++; // increment a and b
			b++; // increment a and b
		}
		else { // if l <= r, then leave it be and increment a
			a++;
		}
	}
	

}



void mergeSortAct(int arr[], int l, int r)
{
	
	if (l < r)
	{
		
		
		int  m= l + (r - l) / 2;

		// Sort first and second halves
		mergeSortAct(arr, l, m);
		mergeSortAct(arr, m + 1, r);
		//a = l; // create temp variable pointing at first element in first half
		//b = m + 1;
		merge(arr, l, m, r);
	}
}
void mergeSort(int a[], int arraySize) {

	mergeSortAct(a, 0, arraySize - 1);
}


//int main()
//{
//	
//	int arr[] = { 9, 11, 13, 5, 7, 7, 16, 1, 83, 2 };
//	int arr_size = sizeof(arr) / sizeof(arr[0]);
//
//	printf("Given array is \n");
//	printArray(arr, arr_size);
//	printf("\nwith length: %d\n", arr_size);
//
//	mergeSort(arr, arr_size);
//
//	cout << endl;
//	printf("Sorted array is \n");
//	printArray(arr, arr_size);
//	while(1){
//	
//	}
//}
