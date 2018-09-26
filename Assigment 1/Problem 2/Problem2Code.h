#include<iostream>
#include <cmath>
#include <string>
using namespace std;
template <class Object>
class ArbitraryQueueArray {
public:

#define startsize 4
	Object *a = new Object[startsize];
	int top = -1;
	int rear = -1;
	int currentsize = 4;
	void resize(int size) {
		Object *copy = new Object[size];
		for (int i = 0; i <= top; i++) {
			copy[i] = a[i];
		}
		a = copy;
		
	}
	void Push(Object object) {//add
						 
		if (top == currentsize - 1) {//structure is empty
			cout << "intiated increase" << endl;
			resize(2 * currentsize);
			currentsize = currentsize * 2;
		}
		a[++top] = object;
	}
	void Enqueue(Object object) {
		int pointer = 0;
		if (top == currentsize - 1) {//structure is empty
			cout << "intiated increase" << endl;
			resize(2 * currentsize);
			currentsize = currentsize * 2;
		}
		if (top == rear) {
			a[++top] = object;
		}
		else {
			for (int i = top; i >= 0; --i) {
				a[i + 1] = a[i];
			}
			++top;
			a[rear + 1] = object;
		}
	}
	void Dequeue() {
		int pointer = 0;
		if (top == -1) {
			cout << "Underflow" << endl;
		}
		else {
			//a[0] = NULL;
			cout << a[0] << " was just removed" << endl;
			for (int i = 0; i <= top; ++i) {
				a[i] = a[i + 1];
				
			}
			--top;
		}
		if (top + 1 == currentsize / 4 && currentsize > 4) {
			cout << "intiated decrease" << endl;
			resize(currentsize / 2);
			currentsize = currentsize / 2;
		}
	}
	void Pop() {
		if (top == -1) {
			cout << "Underflow" << endl;
		}
		else {
			cout << a[top] << " was just removed" << endl;
			//a[top] = NULL;
			top--;
		}
		if (top + 1 == currentsize / 4 && currentsize > 4) {
			cout << "intiated decrease" << endl;
			resize(currentsize / 2);
			currentsize = currentsize / 2;
		}
	}
	void display() {// not used but can be called
		int point;

		point = top;
		while (point != -1) {
			cout << a[point] << endl;
			point--;


		}
	}
	void Traverse(int index) {// index starts at 0
		int ref = top - index;
		int point;
		point = top;
		if (index > top  || index < 0)
		{
			cout << "invalid input" << endl;
		}
		else {

			for (int i = top; i > ref; --i) {
				--point;
			}
			cout << a[point] << endl;

		}
	}
};
