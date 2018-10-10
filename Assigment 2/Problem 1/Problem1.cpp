#include<iostream>
#include <cmath>
#include <string>

using namespace std;
void Problem1(int a[], int arraySize) {
	//int rem[5];
	int data[10];
	int cntzero = 0;
	int cnt2 = 0;
	int val;
	int tmp3;
	int base = 0;
	int divider;
	int valcnt = 0;
	int output[arraySize];//if issues occur please set to size of a
	int i, j, k, l, m, n = 0;
	//cout << " This ran" << endl;
	while (cntzero < arraySize) {
		cnt2 = 0;
		//cout << " This ran" << endl;
		for (i = 0; i < 10; ++i) {//resetting data to zero
			data[i] = 0;

		}
		divider = pow(10, base);
		cntzero = 0;
		for (j = 0; j < arraySize; ++j) {
			//	rem[j] = (a[j] / divider) % 10;
			++data[(a[j] / divider) % 10];
			if ((a[j] / divider) % 10 == 0) {
				++cntzero;
			}

		}
		++base;
		//cout << " This ran" << endl;

		//for (k = 0; k < arraySize; ++k) {//printing for loop
		//	cout << a[k] << ", ";

		//}
		//cout << endl;
		if (cntzero < arraySize) {
			for (i = 1; i <= 9; ++i) {
				data[i] += data[i - 1];
			}
			
			
			
			for (i = arraySize-1; i >= 0; --i)
			{
				output[data[((a[i] / divider) % 10)] - 1] = a[i];
				data[(a[i] / divider) % 10]--;
			}

			
			for (i = 0; i < arraySize; ++i) {
				a[i] = output[i];
			}
		}
		

	}
}
//int main() {
//	int arraypass[5] = {32,  47, 7, 236, 229 };
//	int arr_size = sizeof(arraypass) / sizeof(arraypass[0]);;
//	Problem1(arraypass, arr_size);
//	while (1) {
//
//	}
//}
