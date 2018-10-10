# Name - Desmond Johnson

## This contains the code for problem 2. Code that adds the ability to use a ui and the code that was use to test this will be pasted below.

// below code can be implemented into main function if you wanted a UI
/*ArbitraryQueueArray<string> example;
	ArbitraryQueueArray<int> example2;
	ArbitraryQueueArray<double> example3;
	ArbitraryQueueArray<float> example4;
	int choice, choices, choicei, choiced, choicef;
	string value, value2, index, test;
	int valueint, value2int, indexint, testint;
	double valuedouble, value2double, indexdouble, testdouble;
	float valuefloat, value2float, indexfloat, testfloat;
	string phrases;
	cout << "Press 1 to add strings, 2 to add int, 3 to add double, 4 to add float" << endl;
	cin >> choice;
	if (choice != 1 && choice != 3 && choice != 2 && choice != 4) {
		cout << "Invalid Entry " << endl;
	}
	while (1) {
		

		if (choice == 1) {
			cout << "Press 1 to add an item to top, 2 add an item to the bottom, 3 to delete an item from the bottom, 4 to delete an item from the top , 5 to display the item(s) and 6 to display a specific item" << endl;
			cin >> choices;
			if (choices != 1 && choices != 3 && choices != 2 && choices != 4 && choices != 5 && choices != 6) {
				cout << "Invalid Entry " << endl;
				continue;
			}
			switch (choices) {
			case 1: cout << "Add what?" << endl;
				cin.get();
				getline(cin, value);
				example.Push(value);
				break;
			}
			switch (choices) {
			case 2: cout << "Add what ?" << endl;
				cin.get();
				getline(cin, value);
				example.Enqueue(value);
				break;
			}
			switch (choices) {
			case 3: cout << "Deleted" << endl;
				example.Dequeue();
				break;
			}
			switch (choices) {
			case 4: cout << "Deleted" << endl;
				//	example.pop();
				break;
			}
			switch (choices) {
			case 5: cout << "Here is the contents" << endl;
				example.display();
				break;
			}
			switch (choices) {
			case 6: cout << "What position would you like?" << endl;
				cin >> indexint;
				cout << "Here it is" << endl;
				example.Traverse(indexint);
				break;
			}
		}
		else if (choice == 2) {
			cout << "Press 1 to add an item to top, 2 add an item to the bottom, 3 to delete an item from the bottom, 4 to delete an item from the top , 5 to display the item(s) and 6 to display a specific item" << endl;
			cin >> choicei;
			if (choicei != 1 && choicei != 3 && choicei != 2 && choicei != 4 && choicei != 5 && choicei != 6) {
				cout << "Invalid Entry " << endl;
				continue;
			}
			switch (choicei) {
			case 1: cout << "Add what?" << endl;
				cin >> valueint;
				example2.Push(valueint);
				break;
			}
			switch (choicei) {
			case 2: cout << "Add what ?" << endl;
				cin >> valueint;
				example2.Enqueue(valueint);
				break;
			}
			switch (choicei) {
			case 3: cout << "Deleted" << endl;
				example2.Dequeue();
				break;
			}
			switch (choicei) {
			case 4: cout << "Deleted" << endl;
				example2.Pop();
				break;
			}
			switch (choicei) {
			case 5: cout << "Here is the contents" << endl;
				example2.display();
				break;
			}
			switch (choicei) {
			case 6: cout << "What position would you like?" << endl;
				cin >> indexint;
				cout << "Here it is" << endl;
				example2.Traverse(indexint);
				break;
			}
		}
		else if (choice == 3) {
			cout << "Press 1 to add an item to top, 2 add an item to the bottom, 3 to delete an item from the bottom, 4 to delete an item from the top , 5 to display the item(s) and 6 to display a specific item" << endl;
			cin >> choiced;
			if (choiced != 1 && choiced != 3 && choiced != 2 && choiced != 4 && choiced != 5 && choiced != 6) {
				cout << "Invalid Entry " << endl;
				continue;
			}
			switch (choiced) {
			case 1: cout << "Add what?" << endl;
				cin >> valuedouble;
				example3.Push(valuedouble);
				break;
			}
			switch (choiced) {
			case 2: cout << "Add what ?" << endl;
				cin >> valuedouble;
				example3.Enqueue(valuedouble);
				break;
			}
			switch (choiced) {
			case 3: cout << "Deleted" << endl;
				example3.Dequeue();
				break;
			}
			switch (choiced) {
			case 4: cout << "Deleted" << endl;
				example3.Pop();
				break;
			}
			switch (choiced) {
			case 5: cout << "Here is the contents" << endl;
				example3.display();
				break;
			}
			switch (choiced) {
			case 6: cout << "What position would you like?" << endl;
				cin >> indexint;
				cout << "Here it is" << endl;
				example3.Traverse(indexint);
				break;
			}
		}
		else if (choice == 4) {
			cout << "Press 1 to add an item to top, 2 add an item to the bottom, 3 to delete an item from the bottom, 4 to delete an item from the top , 5 to display the item(s) and 6 to display a specific item" << endl;
			cin >> choicef;
			if (choiced != 1 && choicef != 3 && choicef != 2 && choicef != 4 && choicef != 5 && choicef != 6) {
				cout << "Invalid Entry " << endl;
				continue;
			}
			switch (choicef) {
			case 1: cout << "Add what?" << endl;
				cin >> valuefloat;
				example4.Push(valuefloat);
				break;
			}
			switch (choicef) {
			case 2: cout << "Add what ?" << endl;
				cin >> valuefloat;
				example4.Enqueue(valuefloat);
				break;
			}
			switch (choicef) {
			case 3: cout << "Deleted" << endl;
				example4.Dequeue();
				break;
			}
			switch (choicef) {
			case 4: cout << "Deleted" << endl;
				example4.Pop();
				break;
			}
			switch (choicef) {
			case 5: cout << "Here is the contents" << endl;
				example4.display();
				break;
			}
			switch (choicef) {
			case 6: cout << "What position would you like?" << endl;
				cin >> indexint;
				cout << "Here it is" << endl;
				example4.Traverse(indexint);
				break;
			}
		}

	}
	example2->Push("hi ma");
	example2->Push("11");
	example2->Enqueue("top");
	example2->Enqueue("2");
	example2->Enqueue("2");
	example2->Pop();
	example2->Dequeue();
	example2->display();
	example2->Pop();
	example2->display();
	example2->Traverse(1);
		/*example->Push(7);
			example->Push(11);
			example->Enqueue(3);
			example->Enqueue(2);
			example->Enqueue(2);
			example->Pop();
			example->Dequeue();
			example->Pop();
			example->display();
			example->Traverse(2);*/

example2->Push("hi ma");
	example2->Push("11");
	example2->Enqueue("top");
	example2->Enqueue("2");
	example2->Pop();
	example2->Enqueue("2");
	example2->Enqueue("2");
	example2->Pop();
	example2->Dequeue();
	example2->display();
	example2->Pop();
	example2->display();
	example2->Traverse(1); 
