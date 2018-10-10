#include<iostream>
#include <cmath>
#include <string>

using namespace std;
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{

		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{

		int pi = partition(arr, low, high);


		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}

}
void Problem4A(int a[], int arraySize) {

	int temp;
	int last = arraySize - 1;
	int swap;
	int point = 0;
	quickSort(a, 0, arraySize - 1);
	//for (int l = 0; l < arraySize; ++l) {//printing for loop
	//	cout << a[l] << ", ";

	//}
	//cout << endl;

	for (int l = 1; l < arraySize; l = l + 2) {
		if (l + 1 != arraySize) {
			temp = a[l];
			a[l] = a[l + 1];
			a[l + 1] = temp;
		}
	}

	
	//for (int l = 0; l < arraySize; ++l) {//printing for loop
	//	cout << a[l] << ", ";

	//}
}

//int main() {
//	int arraypass[5] = {  32, 62, 42, 71, 7 };
//	Problem4A(arraypass, 5);
//	while (1) {
//
//	}
//}