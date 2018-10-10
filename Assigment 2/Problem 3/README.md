Name - Desmond Johnson (RUID - 191001434)

This contains the code for problem 3. The int main used to test this file will be shown at the bottom.

This directory includes two different versions of the code. A header version and a cpp version. The header version allows you to have the main function in a seperate file. If you choose to use the header version please add #include <Problem3.h> to the top off the code. If you choose to use the cpp code please put main function inside that file.


Please have the following code at the top of the file (if not already present).
""include<iostream>""
""#include <cmath>""
""#include <string>""
""#include <time.h> ""

using namespace std;
//-----------------------
int main() {// remove median, new lap, and midbreak comments
	srand(time(NULL));

	LinkedList* example = new LinkedList();
	example->add(1);
	example->add(7);
	example->add(9);
	example->add(9);
	example->add(3);
	example->add(6);
	example->printList();
	cout << endl;
	cout << endl;
	example->quicksort();
	example->printList();
	while (1) {}
}
