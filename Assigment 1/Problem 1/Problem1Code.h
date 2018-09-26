#include<iostream>
#include <cmath>
#include <string>

using namespace std;
template <class Object>
class chunk {
public:
	Object value;
	chunk *next;

	chunk() {
		value;
		next = NULL;
	}
};


template <class Object>
class ArbitraryQueue {
public:
	
	chunk<Object> *head;
	ArbitraryQueue() {
		head = NULL;
	}
	void Push(Object object) {//add
						 //is my structure empty
		chunk<Object> *temp = new chunk<Object>;
		temp->value = object; // this chunk is now ready to the stack

		if (head == NULL) {//structure is empty
			head = temp;
		}
		else {
			temp->next = head;//
			head = temp;
		}
	}
	void Enqueue(Object object) {//add
					  //is my structure empty
		chunk<Object> *temp = new chunk<Object>;
		chunk<Object> *temp2;
		chunk<Object> *target;
		temp->value = object; // this chunk is now ready to the stack
		if (head == NULL) {//structure is empty
			head = temp;
		}
		else {
			temp2 = head;
			while (temp2->next != NULL) {
				temp2 = temp2->next;
			}
			temp2->next = temp;
			temp->next = NULL;
			//temp->next = top;//
			//top = temp;
		}

	}
	void Pop() {
		chunk<Object> *temp;
		temp = head;
		if (head == NULL)
		{
			temp = NULL;
			cout << "Empty stack. Nothing to delete" << endl;
		}
		else {
			head = head->next;
			cout << temp->value << " was just removed" << endl;
			delete temp;
		}
	}
	void Dequeue() {
		//delete an element
		chunk<Object> *temp;

		//is the stack empty
		if (head == NULL)
		{
			temp = NULL;
			cout << "Empty stack. Nothing to delete" << endl;
		}
		else if (head->next == NULL) {
			temp = head;
			cout << temp->value << " was just removed" << endl;
			delete temp;
			head = NULL;
		}
		else {
			chunk<Object> *target;//point to one you wanna delete
						  //if not
			target = head;
			temp = target;
			while (target->next != NULL) {
				temp = target;//temp will always be before target
				target = target->next;
			}
			cout << target->value << " was just removed" << endl;
			delete target;
			temp->next = NULL; //grounds second to last
			//delete target;

		}
	}
	void display() {//not used in this code but can be called 
		chunk<Object> *traverse;

		traverse = head;
		while (traverse != NULL) {
			cout << traverse->value << endl;
			traverse = traverse->next;


		}
	}
	void Traverse(int index) {
		chunk<Object> *traverse;
		int cnt = 0;
		traverse = head;
		while (traverse != NULL) {
			if (cnt == index) {
				cout << traverse->value << endl;
				break;
			}
			traverse = traverse->next;
			cnt++;


		}
		if (index > cnt || index < 0) {
			cout << "The index entered is invalid" << endl;
		}
	}


};