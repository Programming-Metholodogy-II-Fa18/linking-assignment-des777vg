#include<iostream>
#include <cmath>
#include <string>
#include <cstdio> 
#include <time.h> 
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



class LinkedList {
public:

	chunk *head;
	LinkedList() {
		head = NULL;
	}
	chunk *clonehead;

	void add(int a) {//add
						 //is my structure empty
		chunk *temp = new chunk;
		chunk *temp2 = new chunk;
		chunk *end;
		temp->value = a; // this chunk is now ready to the stack
		temp2->value = a;
		if (head == NULL) {//structure is empty
			head = temp;
		}
		else {
			temp->next = head;//
			head = temp;
		}
		//end = FindLastPri(head);// dont need
		//cout << "this is the last value of the array " << end->value << endl;
	}
	void Randomize() {
		int cnt = counter();
		int r1 = rand() % (cnt - 1);
		chunk *temp;//pointers for swapping
		chunk *temp2;//pointers for swapping
		chunk *temp3;
		int tmp_stor;//holds value while swapping
		int r2 = rand() % 95 + 5;//number of swaps
		temp = head;
		temp2 = head;
		temp3 = head;
		//cout << r1 << endl;
		int nav1 = 0;
		int nav2 = 0;
		int nav3 = 0;
		while (r2 != 0) {
			while (nav3 <= r1) {
				temp3 = temp3->next;
				++nav3;
			}
			tmp_stor = temp3->value;
			temp3->value = head->value;
			head->value = tmp_stor;
			r1 = rand() % (cnt - 1);
			while (nav1 <= r1) {
				temp = temp->next;
				++nav1;
			}
			r1 = rand() % (cnt - 1);
			//cout << r1 << endl;
			while (nav2 <= r1) {
				temp2 = temp2->next;
				++nav2;
			}
			tmp_stor = temp->value;
			temp->value = temp2->value;
			temp2->value = tmp_stor;
			r1 = rand() % (cnt - 1);
			//cout << r1 << endl;
			nav1 = 0;
			nav2 = 0;
			temp = head;
			temp2 = head;
			--r2;
		}
	}
	chunk * FindLastPri(chunk* ptr) {
		while (ptr->next != NULL && ptr != NULL) {
			ptr = ptr->next;
		}
		return ptr;
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
	void partition(chunk  *head, chunk *end, chunk **i, chunk **j, chunk **k, int counter)
	{
		chunk *pivot = new chunk;
		pivot->value = head->value;
		chunk* prev = head;
		chunk* cur = head, *tail = pivot;//dont need these
		chunk* mid = head;
		chunk* prevmid = head;
		chunk* prevtail = end;
		chunk* low = head;
		chunk* prevlow = head;
		chunk* traverse = head;
		//cout << " new lap" << endl;
		int firstcnt = 0;
		int cnt = 0;
		int tmpmedian;
		while (traverse != end) {

			traverse = traverse->next;
		}
		*k = traverse;
		traverse = head;
		while (traverse != end) {
			++cnt;
			traverse = traverse->next;
		}
		if (cnt == counter) {
			chunk* headnext = head->next;
			//cout << head->value << " " << headnext->value << " " << end->value << " " << endl;
			if (head->value >= headnext->value && head->value <= end->value) {
				//head is mid
				//cout << head->value << endl;
				//cout << "value of media is " << head->value << endl;
			}
			else if (head->value <= headnext->value && head->value >= end->value) {
				//head is mid
				//cout << "value of median is " << head->value << endl;
				//cout << head->value << endl;
			}
			else if (headnext->value >= head->value && headnext->value <= end->value) {
				//headnext is mid
			//	cout << "value of median is " << headnext->value << endl;
				tmpmedian = head->value;
				head->value = headnext->value;
				headnext->value = tmpmedian;
			}
			else if (headnext->value <= head->value && headnext->value >= end->value) {
				//headnext is mid
				//cout << "value of median is " << headnext->value << endl;
				tmpmedian = head->value;
				head->value = headnext->value;
				headnext->value = tmpmedian;
			}
			else if (end->value >= headnext->value && end->value <= head->value) {
				//end is mid
				//cout << "value of median is " << end->value<< endl;
				tmpmedian = head->value;
				head->value = end->value;
				end->value = tmpmedian;
			}
			else if (end->value <= headnext->value && end->value >= head->value) {
				//end is mid
			//	cout << "value of median is " << end->value << endl;
				tmpmedian = head->value;
				head->value = end->value;
				end->value = tmpmedian;
			}
			//printList();
			cout << endl;
		}
		traverse = head;
		pivot->value = head->value;

		int pvt_val = pivot->value;
		//chunk* prev2 = NULL;
		int temp_store;

		if (head->next == end) {
			cout << "Compairing pointer " << end->value << " to " << head->value << endl;
			if (end->value < head->value) {
				cout << "Swapping " << end->value << " with " << head->value << endl;
				temp_store = end->value;
				end->value = head->value;
				head->value = temp_store;
			}
			*i = head;

			*j = end;
			(*k) = end;

			cout << "Value of current list after partition is complete" << endl;
			while (traverse != end) {
				cout << traverse->value << ",";
				traverse = traverse->next;
			}
			cout << traverse->value;
			cout << endl;
			traverse = head;
			return;
		}


		while (prevmid != prevtail)
		{
			cout << "Compairing pointer " << pvt_val << " to " << mid->value << endl;
			if (mid->value < pvt_val)
			{
				//cout << " less than" << endl;
				//cout << " " << mid->value << " " << " " << pivot->value << " " << prevtail->value << " " << " " << endl;
				// First node that has a value less than the pivot - becomes 
				// the new head 

				cout << "Swapping " << prevtail->value << " with " << mid->value << endl;
				temp_store = mid->value;
				mid->value = low->value;
				low->value = temp_store;
				prevlow = low;
				prevmid = mid;
				//	if (mid->next == NULL) {
					//	cout << " in mid break" << endl;
				//		break;
				//	}



				mid = mid->next;
				low = low->next;

				//cur = cur->next;
				//prev2 = cur;
			}
			else if (mid->value == pvt_val) {
				//cur = cur->next;
				//cout << pvt_val << endl;
				prevmid = mid;
				mid = mid->next;
				//cout << " equal"  <<  endl;
				if (mid == NULL) {
					cout << " in mid break" << endl;
					break;
				}
			}
			else
			{
				//cout << " greater than"  << endl;
				temp_store = prevtail->value;
				cout << "Swapping " << prevtail->value << " with " << mid->value << endl;
				prevtail->value = mid->value;
				mid->value = temp_store;//prev2 will serve as mid  and so does curv
				prev = head;
				if (prev != NULL || prevtail != head) {
					while (prev->next != prevtail && prev != NULL) {
						//prev = prev->next;
					//	cout << "Hi"  << endl;
						if (prev->next == NULL) {
							cout << "end" << endl;
							cout << prevtail->value << " " << prevmid->value << endl;
							break;
						}
						prev = prev->next;
					}
				}
				if (prev != NULL) {
					prevtail = prev;
				}
				//cout << " "<< mid->value << " "  << " " << prevmid->value << " " << prevtail ->value << " " << " " << endl;
			}

		}
		cout << "Value of current list after partition is complete" << endl;
		while (traverse != end) {
			cout << traverse->value << ",";
			traverse = traverse->next;
		}
		cout << traverse->value;

		cout << endl;
		// If the pivot data is the smallest element in the current list, 
		// pivot becomes the head 



		if (prevtail->next == NULL && mid == NULL) {
			(*i) = prevlow;
			(*j) = prevmid;
			//(*k) = prevmid;
			//cout << "both were null" << endl;

		}
		else if (mid == NULL) {
			//(*newEnd) = tail;
			(*i) = prevlow;
			(*j) = prevmid;
			//	(*k) =prevmid;
				//cout << "mid was null" << endl;
		}
		else if (end == prevmid) {
			//(*newEnd) = tail;
			(*i) = prevlow;
			(*j) = prevmid;
			//	(*k) = mid;
			//cout << "end next was null" << endl;
		}
		else if (mid->next == NULL) {
			//(*newEnd) = tail;
			(*i) = prevlow;
			(*j) = mid;
			//	(*k) = mid;
				//cout << "mid next was null" << endl;
		}
		else if (end->next == mid) {
			//(*newEnd) = tail;
			(*i) = prevlow;
			(*j) = end;
			//	(*k) = mid;
			//cout << "end next was null" << endl;
		}
		else if (prevtail->next == NULL) {
			//(*newEnd) = tail;
			(*i) = prevlow;
			(*j) = prevtail;
			//	(*k) = mid->next;
				//cout << "prevtail next was  null" << endl;
		}
		else {
			(*i) = prevlow;
			(*j) = prevtail->next;
			//	(*k) = mid->next;
				//cout << "else ran" << endl;
		}

	}


	//here the sorting happens exclusive of the end node 
	chunk *quickSortRecur(chunk *head, chunk*end, int counter)
	{
		// base condition 
		if (head == NULL || head == end) {
			cout << "Partition did not need to run because there is only one element in the list/sublist or original lis is empty" << endl;
			return head;
		}
		//chunk *newHead = NULL, *newEnd = NULL;//should be able to delete and remove from code
		chunk * i;
		chunk * j;
		chunk * k;
		// Partition the list, newHead and newEnd will be updated 
		// by the partition function 
		//cout << head->value << "  " << end->value << endl;
		partition(head, end, &i, &j, &k, counter);// &newHead reference pointer

		// If pivot is the smallest element - no need to recur for 
		// the left part. 

		quickSortRecur(head, i, counter);
		// Recur for the list after the pivot element 
		// cout << "run this" << endl;
		// end = FindLastPri(head);// updates end in terms of actual one
		quickSortRecur(j, k, counter);

		return head;
	}

	// The main function for quick sort. This is a wrapper over recursive 
	// function quickSortRecur() 
	void quicksort()
	{
		Randomize();
		//printList();
		cout << endl;
		int cnt2 = counter() - 1;
		head = quickSortRecur(head, FindLastPri(head), cnt2);
		return;
	}
	void printList() {//displays stack
		chunk *traverse;

		traverse = head;
		while (traverse != NULL) {
			cout << traverse->value << ",";
			traverse = traverse->next;


		}
	}

	int  counter() {
		chunk *traverse;
		int cnt = 0;
		traverse = head;
		while (traverse != NULL) {
			traverse = traverse->next;
			++cnt;
		}
		return cnt;
	}



};