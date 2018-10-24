#include<iostream>
#include <cmath>
#include <string>
using namespace std;
int currentSize;

class DaryHeap
{
private:
	int numKids;
	int size;
	int *arr;
public:

	DaryHeap(int k)
	{
		currentSize = 0;
		numKids = k;
		size = 10;
		arr = new int[size];
		
	}
	void doubleArray() {
		int newSize = 2 * size;
		int *copy;
		copy = new int[newSize];
		for (int i = 0; i < size; i++) {
			copy[i] = arr[i];
		}
		arr = copy;

	}
	void sink(int index)
	{
		int MaxChildLoca;
		int *child;
		int tmp;
		child = new int[numKids + 1];

		while (1)
		{

			for (int i = 1; i <= numKids; i++){
				 if ((numKids*index + i) < currentSize) {
					 child[i] = (numKids*index + i);
				}
				 else {
					 
					 child[i] = -1;
				 }
				}

			int MaxChild = -1;

			for (int i = 1; i <= numKids; i++)
			{
				if (child[i] != -1 && arr[child[i]] > MaxChild)
				{
					MaxChildLoca = child[i];
					MaxChild = arr[child[i]];
				}
			}

			if (MaxChild == -1)
				break;

			if (arr[index] < arr[MaxChildLoca]) {
				tmp = arr[index];
				//swap(arr[index], arr[MaxChildLoca]);
				arr[index] = arr[MaxChildLoca];
				arr[MaxChildLoca] = tmp;
			}
			index = MaxChildLoca;
		}
	}

	void sinkSort(int a[], int len)
	{
		int MaxChildLoca;
		int *child;
		int index = 0;
		int tmp2;
		child = new int[numKids + 1];

		while (1)
		{

			for (int i = 1; i <= numKids; i++) {
				if ((numKids*index + i) < len) {
					child[i] = (numKids*index + i);
				}
				else {

					child[i] = -1;
				}
			}

			int MaxChild = -1;

			for (int i = 1; i <= numKids; i++)
			{
				if (child[i] != -1 && a[child[i]] > MaxChild)
				{
					MaxChildLoca = child[i];
					MaxChild = a[child[i]];
				}
			}

			if (MaxChild == -1)
				break;

			if (a[index] < a[MaxChildLoca]) {
				tmp2 = a[index];
				//swap(a[index], a[MaxChildLoca]);
				a[index] = a[MaxChildLoca];
				a[MaxChildLoca] = tmp2;
				
			}
			index = MaxChildLoca;
		}
	}


	void swim(int index)
	{

		int parent = (index - 1)/numKids;
		int tmp;
		while (parent >= 0)
		{
			if (arr[index] > arr[parent]) 
			{
				tmp = arr[index];
				//swap(arr[index], arr[parent]);
				arr[index] = arr[parent];
				arr[parent] = tmp;
				index = parent;
				parent = (index - 1) / numKids;
			}
			else
				break;
		}
	}

 

	void insert(int elem)
	{
	
		if (currentSize == size) {
			cout << "intiated increase" << endl;
			doubleArray();
			size = size * 2;
		}
		arr[currentSize] = elem;

		currentSize = currentSize + 1;

		swim(currentSize-1); 
	}


	int* daryHeapsort()
	{
		int tmp;
		int *clone;
		clone = new int[currentSize - 1];
		for (int i = 0; i <= currentSize - 1; ++i) {
			clone[i]=arr[i];
		}
		for (int i = currentSize - 1; i >= 0; i--)
		{
			tmp = clone[0];
			//swap(clone[0], clone[i]);
			clone[0] = clone[i];
			clone[i] = tmp;
			sinkSort(clone, i);
		}
		return clone;
	}

	int delMax()
	{
		int max = arr[0];
		arr[0] = arr[currentSize - 1];

		currentSize = currentSize - 1;
		sink(0);

		return max;
	}
	void display() {
		
		for (int i = 0; i <= currentSize-1; ++i) {
			cout << arr[i] << endl;
		}
	}
};

//int main() {
//	DaryHeap*example = new DaryHeap(3);
//	//DaryHeap*example2 = new DaryHeap[];
//	example->insert(9);
//	example->insert(4);
//	example->insert(20);
//	example->insert(1);
//	example->insert(15);
//	example->insert(7);
//	example->insert(2);
//	example->insert(8);
//	example->insert(9);
//	example->insert(10);
//	example->insert(11);
//	//example->display();
//	int max =example->delMax();
//	cout << "This is the max " << max << endl;
//	cout <<  endl;
//	example->display();
//	cout << endl;
//	int *sort =example->daryHeapsort();
//	for (int i = 0; i < currentSize; ++i) {
//		cout << sort[i] << endl;
//	}
//	// cant retrun arrays in c++ only pointers so please test function using the following tecqnique
//	while (1) {
//
//	}
//}