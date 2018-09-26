#include<iostream>
#include <cmath>
#include <string>

using namespace std;

class chunk {
public:
	int value;
	chunk *next;

	chunk() {
		value = 0;
		next = NULL;
	}
};



class Stack {
public:

	chunk *head;
	Stack() {
		head = NULL;
	}
	chunk *clonehead;

	void Push(int data) {//add
						 //is my structure empty
		chunk *temp = new chunk;
		chunk *temp2 = new chunk;
		temp->value = data; // this chunk is now ready to the stack
		temp2->value = data;
		if (head == NULL) {//structure is empty
			head = temp;
		}
		else {
			temp->next = head;//
			head = temp;
		}
		

	}

	void Pop() {
		chunk *temp;
		chunk *temp2;
		temp = head;
		temp2 = clonehead;
		if (head == NULL)
		{
			temp = NULL;
			cout << "Empty stack. Nothing to delete" << endl;
		}
		else {
			head = head->next;
			delete temp;
		}
		if (clonehead != NULL) {
			clonehead = clonehead->next;
			delete temp2;
		}
	}

	void display() {//displays stack
		chunk *traverse;

		traverse = head;
		while (traverse != NULL) {
			cout << traverse->value << endl;
			traverse = traverse->next;


		}
	}
	void displayClone() {//displays stack clone that has properties requested for past peek
		chunk *traverse;

		traverse = clonehead;
		while (traverse != NULL) {
			cout << traverse->value << endl;
			traverse = traverse->next;


		}
	}
	
	void InsertionSort() {
		clonehead = NULL;
		clone(head);
		chunk *temp;//pointer for sorting
		chunk *temp2;
		int t_val;
		if (head == NULL || head->next == NULL) {
			cout << "Nothing to sort" << endl;
			return;
		}
		temp = head->next;
		while (temp != NULL) {
			int stored_value = temp->value;
			temp2 = head;
			int found = 0;
			while (temp != temp2) {
				if (temp2->value > temp->value && found == 0) {
					stored_value = temp2->value;// copy current value of temp2
					cout << "Swapped " << temp2->value << " with " << temp->value << endl;
					temp2->value = temp->value;// set temp2 to lower value
					display();
					//this means the first spot is greater than next copy value ina variable and movenext value to current
					found = 1;
					temp2 = temp2->next;// point to temp and they will now be pointing at the same spot
				}
				else {
					if (found == 1) {
						t_val = stored_value;
						stored_value = temp2->value;
						cout << "Swapped " << temp2->value << " with " << t_val << endl;
						temp2->value = t_val;
						display();
					}
					temp2 = temp2->next;
				}
			}
			cout << "Replacing " << temp2->value << " with stored_value " << stored_value << endl;
			temp2->value = stored_value;
			temp = temp->next;
			display();
			//cout << "Moving pointer forward" << endl;// shows where pointer is
		}
		cout << "Sort Finished!" << endl;
	}
	void clone(chunk* Ptr) {
		if (Ptr == NULL) {
			return;
		}
		chunk *temp2;

		chunk *clonetemp = new chunk;
		clonetemp->value = Ptr->value;
		if (clonehead == NULL) {//structure is empty
			clonehead = clonetemp;
		}
		else {
			temp2 = clonehead;
			while (temp2->next != NULL) {
				temp2 = temp2->next;
			}
			temp2->next = clonetemp;
			clonetemp->next = NULL;
		}
		clone(Ptr->next);
	}
	void Peek() {
		chunk *traverse;
		traverse = head;
		if (traverse != NULL) {
			cout << traverse->value << endl;
		}
		else {
			cout << "The stack is empty" << endl;
		}
	}
	void pastPeek() {
		chunk *traverse;
		traverse = clonehead;
		if (traverse != NULL) {
			cout << traverse->value << endl;
		}
		else {
			cout << "The stack is empty" << endl;
		}
	}
};

