#include<iostream>
#include <cmath>
#include <string>

using namespace std;
class Problem4 {
public:
	void ProblemFourC(int num) {
		int x[70];//was selected because int can only be so high
		int total = 0;
		int cnt = 0;
		int i = 0, k = 0, j = 0;
		for (i = 0; i <= 4; ++i) {
			for (j = 0; j <= 4; ++j) {
				for (k = 0; k <= 4; ++k) {
					if (cnt <= 69) {
						x[cnt] = pow(7, k)*pow(9, j)*pow(15, i);
					}
					++cnt;
				}
			}
		}
	
		int temp_store;//insertion sort
		int pointerBeforei;
		for (int i = 1; i < 70; i++) {
			temp_store = x[i];
			pointerBeforei = i - 1;

			while (pointerBeforei >= 0 && x[pointerBeforei] > temp_store) {
				x[pointerBeforei + 1] = x[pointerBeforei];
				pointerBeforei = pointerBeforei - 1;
			}
			x[pointerBeforei + 1] = temp_store;
		}
		if (num <= 69 && num>=0) {
			cout << x[num] << endl;
		}
		else {
			cout <<"The number you entered is outside the scope of the array of integers or invalid" << endl;
		}
	}
	void ProblemFourA(string test) {
		int length;
		string testrev = test;
		int cnt = 0;
		for (int i = test.size() - 1; i >= 0; --i) {
			testrev[cnt] = test[i];
			cnt++;
		}
		cout << testrev << endl;
	}
	void ProblemFourB(int test2[3][4], int num) {
		int x[12];
		int cnt = 0;
		int found = 0;
		int leftPointer = 0;
		int rightPointer = (sizeof(x) / sizeof(int)) - 1;
		
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 4; ++j) {
				x[cnt] = test2[i][j];
				++cnt;
			}

		}

		int temp_store;//insertion sort
		int pointerBeforei;
		for (int i = 1; i < 12; i++) {
			temp_store = x[i];
			pointerBeforei = i - 1;

			while (pointerBeforei >= 0 && x[pointerBeforei] > temp_store) {
				x[pointerBeforei + 1] = x[pointerBeforei];
				pointerBeforei = pointerBeforei - 1;
			}
			x[pointerBeforei + 1] = temp_store;
		}
		while (leftPointer < rightPointer) {
			if (x[leftPointer] + x[rightPointer] == num) {
				cout << x[leftPointer] << ", " << x[rightPointer] << endl;
				found = 1;
				leftPointer++;
			}
			else if (x[leftPointer] + x[rightPointer] < num) {
				leftPointer++;
			}
			else {
				rightPointer--;
			}
		}
		if (found == 0) {
			cout << "No pairs were found" << endl;
		}

	}
}; 
