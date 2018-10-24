Name - Desmond Johnson (RUID - 191001434)
This contains the code for problem 2. The int main used to test this file will be commented out at the bottom of the cpp file. 

Please note that c++ does not let you return arrays in the traditional manner. The function sortedTree returns a pointer to the start of the array. An example of how to use the pointer will be shown below.

int *sortarr = example->sortedTree();
		for (int i = 0; i < size; ++i) {
			cout << sortarr[i] << ",";
		}

Based on my interpertation of the assigment I made it so balanceTreeOne returns the pointer for the head of the new sorted BST. An example of how to use the pointer will be shown below.

	Node * balancetop = example->balanceTreeOne();//returns top2
		example->PrintInOrderPri(balancetop);



