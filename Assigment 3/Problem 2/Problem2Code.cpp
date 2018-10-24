#include<iostream>
#include <cmath>
#include <string>

using namespace std;
int *sortedarr;
int cnt;
class Node {
public:
	int value;
	Node *left;//smaller
	Node *right;//greater
	Node *parent;
	Node() {
		value = 0;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};
// values of left has to be less than the parent and right has to be greater
class BST {
public:
	Node * top;
	Node * top2;//for balanced tree via array
	BST() {
		top = NULL;
		top2 = NULL;
	}
	Node* createLeaf(int key) {
		Node *n = new Node;
		n->value = key;
		n->left = NULL;
		n->right = NULL;
		return n;
	}
	void put(int key) {
		putPri(key, top);
	}
	
	void putPri(int key, Node* Ptr) {
		if (top == NULL)
		{
			top = createLeaf(key);
		}
		else if (key < Ptr->value) {
			if (Ptr->left != NULL) {
				putPri(key, Ptr->left);
			}
			else {
				Ptr->left = createLeaf(key);
				Ptr->left->parent = Ptr;
			}
		}
		else if (key > Ptr->value) {
			if (Ptr->right != NULL) {
				putPri(key, Ptr->right);
			}
			else {
				Ptr->right = createLeaf(key);
				Ptr->right->parent = Ptr;
			}
		}
		else {// key == ptr
			cout << "The key " << key << " has already been added to the tree" << endl;
		}
	}
	void put(int a[]) {
		int size = sizeof(a)+1;
		//cout << size << endl;
		for (int i = 0; i < size; ++i) {
			putPri(a[i], top);
		}
	}
	int search(int key) {//not needed for assigment
		int result;
		result =searchPri(key, top);
		return result;
	}
	int searchPri(int key, Node* Ptr) {
		if (Ptr != NULL)
		{
			if (Ptr->value == key) {
				cout << "The key has been found" << endl;
				int keyf = Ptr->value;
				return keyf;
			}
			else {
				if (key < Ptr->value) {
					searchPri(key, Ptr->left);
				}
				else {
					searchPri(key, Ptr->right);
				}
			}
		}
		else {
			cout << "The key was not found" << endl;
			return 0;
		}
	}
	void PrintInOrder() {//not needed for assigment
		PrintInOrderPri(top);
	}
	void PrintInOrderPri(Node* Ptr) {//not needed for assigment
		if (top != NULL) {
			if (Ptr->left != NULL) {	
				PrintInOrderPri(Ptr->left);
			}
			cout << Ptr->value << endl;
			if (Ptr->right != NULL) {
				PrintInOrderPri(Ptr->right);
			}

		}

		else {
			cout << "There is nothing in the tree" << endl;
		}
	}
	void cntInOrderPri(Node* Ptr) {//instead of printing value it increments counter
		if (top != NULL) {
			if (Ptr->left != NULL) {

				cntInOrderPri(Ptr->left);
			}
			++cnt;
			if (Ptr->right != NULL) {

				cntInOrderPri(Ptr->right);
			}

		}

		else {
			cout << "There is nothing in the tree" << endl;
		}
	}
	void arrInOrderPri(Node* Ptr) {//instead of printing value it increments counter
		if (top != NULL) {
			if (Ptr->left != NULL) {
			
				arrInOrderPri(Ptr->left);
			}
			sortedarr[cnt] = Ptr->value;
			++cnt;
			if (Ptr->right != NULL) {
				
				arrInOrderPri(Ptr->right);
			}

		}

		else {
			cout << "There is nothing in the tree" << endl;
		}
	}
	
	int returnSize() {
		cnt = 0;
		cntInOrderPri(top);
		return cnt;
	}
	int* sortedTree() {//O(2n)
		int *arr;
		int size = returnSize();
		sortedarr = new int[size];
		arr = new int[size];
		cnt = 0;
		arrInOrderPri(top);// travers the tree in order and copies the treee
		for (int i = 0; i < size; ++i) {
			arr[i]= sortedarr[i];
		}
		/*for (int i = 0; i < size; ++i) {
				cout << arr[i] << ",";
			}*/
		return arr;
	}
	Node* balanceTreeOne() {
		int *arr = sortedTree();
		int size = returnSize();
		top2 = ArraytoBST(arr, 0, size-1);
		return top2;
	}
	Node* ArraytoBST(int arr[], int beg, int end)
	{
		if (beg > end)
			return NULL;

		int mid = (beg + end) / 2;
		Node *root = createLeaf(arr[mid]);

		root->left = ArraytoBST(arr, beg, mid - 1);

		root->right = ArraytoBST(arr, mid + 1, end);

		return root;
	}

	void PrintPreOrder() {
		PrintPreOrderPri(top);
	}
	void PrintPreOrderPri(Node* Ptr) {
		
		if (top != NULL) {
			cout << Ptr->value << endl;
			if (Ptr->left != NULL) {
				PrintPreOrderPri(Ptr->left);
			}
			if (Ptr->right != NULL) {
				PrintPreOrderPri(Ptr->right);
			}
			
		}

		else {
			cout << "There is nothing in the tree" << endl;
		}

	}
	
	
	Node* returnTop() {
		Node * tmp = top;
		//cout << "The value of tmp is  " << tmp->value << endl;
		return tmp;
	}

	Node* rotateRight(Node* h) {
		
		if (h->left == NULL) {
			return h;
		}
		else {
			Node* originalhead = h;
			Node* x = h->left;
			h->left = x->right;
			x->right = h;

			if (originalhead->parent == NULL) {
				top = x;
				x->parent = originalhead->parent;
				originalhead->parent = x;
				x->parent = NULL;
			}
			else if (originalhead->parent->value < originalhead->value) {
				x->parent = originalhead->parent;
				originalhead->parent->right = x;
				originalhead->parent = x;
			}
			else {
				x->parent = originalhead->parent;
				originalhead->parent->left = x;
				originalhead->parent = x;
			}
			return x;
		}
	}
	Node* rotateLeft(Node* h) {
		//cout << h->value << endl;
		//cout << "The value of original h parent is  " << h->parent->value << endl;
		if (h->right == NULL) {
			return h;
		}
		else {
			Node* originalhead = h;
			Node* x = h->right;
			h->right = x->left;
			x->left = h;

			if (originalhead->parent == NULL) {
				top = x;
				x->parent = originalhead->parent;
				originalhead->parent = x;
				x->parent = NULL;
			}
			else if (originalhead->parent->value < originalhead->value) {
				x->parent = originalhead->parent;
				originalhead->parent->right = x;
				originalhead->parent = x;

			}
			else {
				x->parent = originalhead->parent;
				originalhead->parent->left = x;
				originalhead->parent = x;

			}
			return x;
		}
	}
	void rotateRightLink(Node* h) {
		//cout << h->value << endl;
		//cout << "The value of original h parent is  " << h->parent->value << endl;
		if (h->left == NULL||h==NULL) {
			//return h;
		}
		else {
			Node* originalhead = h;
			Node* x = h->left;
			h->left = x->right;
			x->right = h;

			if (originalhead->parent == NULL) {
				top = x;
				x->parent = originalhead->parent;
				originalhead->parent = x;
				x->parent = NULL;
			}
			else if (originalhead->parent->value < originalhead->value ) {
				x->parent = originalhead->parent;
				originalhead->parent->right = x;
				originalhead->parent = x;
			}
			else {
				x->parent = originalhead->parent;
				originalhead->parent->left = x;
				originalhead->parent = x;
			}
			//return x;
		}
	}
	void rotateLeftLink(Node* h) {
		//cout << h->value << endl;
		//cout << "The value of original h parent is  " << h->parent->value << endl;
		int flag = 0;//indicates if x is a end of branch
		if (h->right == NULL || h == NULL) {
			//return h;
		}
		else {
			Node* originalhead = h;
			if (originalhead->parent != NULL) {
			}
			
			Node* x = h->right;
			
			//if (x->right == NULL && x->left == NULL) {
			//	cout << "flag set" << endl;
			//	flag = 1;
			//}
			h->right = x->left;
			
			x->left = h;

			if (originalhead->parent == NULL) {
				top = x;
				x->parent = originalhead->parent;
				originalhead->parent = x;
				x->parent = NULL;
			}
			else if (originalhead->parent->value < originalhead->value) {
				x->parent = originalhead->parent;
				originalhead->parent->right = x;
				originalhead->parent = x;

			}
			else {
				x->parent = originalhead->parent;
				originalhead->parent->left = x;
				originalhead->parent = x;

			}
			//return x;
			if (x->parent != NULL) {
				//cout << "The value of x parent after everything is " << x->parent->value << endl;
			}
		}
	}
	void transformtoList() {
		transformtoListPri(top);
	}
	void transformtoListPri(Node* ptr) {

		while (ptr->left != NULL) {
			rotateRightLink(ptr);
			//PrintPreOrder();
			//cout << "The value of pointer is " << ptr->value << endl;

			if ( ptr->parent == NULL) {
				break;
			}
			else {
				ptr=ptr->parent;
			}
		}
		if (ptr->right != NULL) {
			//cout << "startedRecurssion" << endl;
			transformtoListPri(ptr->right);
			//cout << "This ran" << endl;
		}
	}
	void transformtoListCheck() {
		transformtoListCheckPri(top);
	}
	void transformtoListCheckPri(Node* ptr) {
		if (top != NULL) {
			while (ptr != NULL) {
				cout << ptr->value << endl;
				ptr = ptr->right;
			}


		}
	}
	void checkLeft() {
		checkLeftPri(top);
	}
	void checkLeftPri(Node* ptr) {
		if (top != NULL) {
			while (ptr != NULL) {
				cout << ptr->value << endl;
				ptr = ptr->left;
			}


		}
	}
	void balanceTreeTwo() {
		if (top != NULL) {
			transformtoList();
			//int checkbal = isBalancedPri2(top);
			//cout << "The status of balance " << checkbal << endl;
			//transformtoListCheck();
			int size = returnSize();
			int logint = log2(size);
			int M = (size + 1) - pow(2, floor(log2(size)));
			Node* temp = top;
			Node ** pointers;

			int K = log2(size) - 1;
			cout << endl;
			for (int i = 0; i < M; ++i) {
				rotateLeftLink(temp);
				/*PrintPreOrder();
				cout << "checking right leaning elements " << endl;
				transformtoListCheck();*/
				if (temp->parent != NULL && temp->parent->right != NULL) {
					temp = temp->parent->right;
				}
			}
			temp = top;
			int cntK = 0;
			int cnt2 = 0;//counts how many pointers to make
			while (temp != NULL) {
				++cnt2;
				if (temp->right == NULL) {
					break;
				}
				else {
					temp = temp->right->right;
				}
			}
			
			temp = top;

			cout << endl;
			while (K > 0) {
				if (K == 1) {
					for (int i = 0; i < 1; ++i) {
						rotateLeftLink(temp);
						/*PrintPreOrder();
						cout << "checking right leaning elements " << endl;
						transformtoListCheck();*/
					}
					//cout << "Ran K==1 case " << endl;
				}
				else {
					for (int i = 0; i < cnt2; ++i) {
						rotateLeftLink(temp);
						/*PrintPreOrder();
						cout << "checking right leaning elements " << endl;
						transformtoListCheck();*/

						if (temp->parent != NULL && temp->parent->right != NULL) {
							temp = temp->parent->right;
						}

					}
					//cout << "Ran K>1 case" << endl;
				}
				temp = top;
				//cout << "Out of for loop" << endl;
				cnt2 = 0;//counts how many pointers to make
				while (temp != NULL) {
					++cnt2;
					if (temp->right == NULL) {
						break;
					}
					else {
						temp = temp->right->right;
					}
				}
				
				temp = top;

				--K;
				cout << endl;
			}
			//checkbal = isBalancedPri2(top);
			//cout << "The status of balance " << checkbal << endl;
		}
		else {
		cout << "There is no nodes in the tree "  << endl;
		}
	}
	};
	 
	//int main() {
	//	BST*example = new BST();
	//	//int checkbal;
	//	int testa[] = { 5, 3, 2,4, 1 };
	//	example->put(9);
	//	example->put(4);
	//	example->put(20);
	//	example->put(1);
	//	example->put(15);
	//	example->put(7);
	//	example->put(2);
	//	
	//	//////example->put(testa);
	//	example->PrintInOrder();
	//	cout << endl;
	//	example->PrintPreOrder();

	//	int result = example->search(3);
	//	cout << "The returned value of result is " << result << endl;
	//	result = example->search(7);
	//	cout << "The returned value of result is " << result << endl;
	//	int size = example->returnSize();
	//	cout << "The size of the tree is " << size << endl;
	//	int *sortarr = example->sortedTree();
	//	cout << "The contents of the sorted array is: ";
	//	for (int i = 0; i < size; ++i) {
	//		cout << sortarr[i] << ",";
	//	}
	//	cout << endl;

	//	//Node * balancetop = example->balanceTreeOne();//returns top2
	//	//example->PrintInOrderPri(balancetop);
	//	//checkbal = example->isBalancedPri(balancetop);
	//	//cout << "The status of balance " << checkbal << endl;
	//	//example->PrintPreOrderPri(balancetop);
	//	Node * top = example->returnTop();
	//	//Node * newtopL = example->rotateLeft(top);
	//	//cout << "The value of new head is  " << newtopL->value << endl;
	//	//cout << endl;*/
	//	/*example->rotateRightLink(top);
	//	example->PrintPreOrder();
	//	cout << endl;*/
	//	
	//	example->balanceTreeTwo();
	//	top = example->returnTop();
	//	example->PrintPreOrder();
	//	//checkbal = example->isBalancedPri2(top);
	//	example->checkLeft();
	//	//cout << "The status of balance " << checkbal << endl;
	//	//example->transformtoList();

	//	//example->transformtoListCheck();

	//	while (1) {

	//	}
	//}
