Name - Desmond Johnson (RUID - 191001434)
This contains the code for problem 2. The int main used to test this file will be shown at the bottom.

Please have the following code at the top of the file (if not already present).
#include<iostream>
#include <cmath>
#include <string>
#include<stdlib.h>
#include<stdio.h>


using namespace std;
//-----------------------

int main()
{
	
	int arr[] = { 9, 11, 13, 5, 7, 7, 16, 1, 83, 2 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("Given array is \n");
	printArray(arr, arr_size);
	printf("\nwith length: %d\n", arr_size);

	mergeSort(arr, arr_size);

	cout << endl;
	printf("Sorted array is \n");
	printArray(arr, arr_size);
	while(1){
	
	}
}