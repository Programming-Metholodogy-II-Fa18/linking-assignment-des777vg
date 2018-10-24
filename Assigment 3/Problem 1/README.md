Name - Desmond Johnson (RUID - 191001434)

This contains the code for problem 1. The int main used to test this file will be commented out at the bottom of the cpp file. 

Please note that c++ does not let you return arrays in the traditional manner. The function daryHeapsort returns a pointer to the start of the array. An example of how to use the pointer will be shown below.

	int *sort =example->daryHeapsort();
	for (int i = 0; i < currentSize; ++i) {
		cout << sort[i] << endl;
	}

Based on my interpertation of the assigment I made it so daryHeapsort does not modify the heap during sort. It copies the heap into another array (clone) and performs the heapsort on that. If you want the original heap to be sorted please swap clone with arr in the daryHeapsort function.

The syntak for calling the constructor with the number of children is DaryHeap*example = new DaryHeap(numberofkids), where numberofkids is an integer.


