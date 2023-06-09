#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** triandri, Node** briliyan);
	bool listEmpty();
	bool delNode();
	void traverse();
};

void CircularLinkedList::addNode() { //write your answer here
	int nim;
	string nama;
	cout << "Enter the number of student: ";
	cin >> nim;
	cout << "Enter the name of student: ";
	cin >> nama;

	Node* newNode = new Node(); //step 1
	newNode->rollNumber = nim;  //step 2
	newNode->name = nama;       //step 2

	/*insert a node in the begining of the list*/
	if (LAST == NULL || nim <= LAST->rollNumber) { //check if data null
		if (LAST != NULL && nim == LAST->rollNumber) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = LAST;     //step 3
		if (LAST != NULL)   
			LAST->next = newNode; //step 4 
		newNode->next = NULL;
		LAST = newNode;
		return;
	}

	/*inserting a node beetwen two node in the list*/
	Node* briliyan = LAST; //step 1.a
	Node* triandri = NULL; //step 1.b
	while (briliyan->next != NULL && briliyan->next->rollNumber) //step 1.c
	{
		triandri = briliyan;
		briliyan = briliyan->next;
	}

	if (briliyan->next != NULL && nim == briliyan->next->rollNumber) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}

	newNode->next = briliyan->next;
	newNode->next = briliyan;
	if (briliyan->next != NULL)
		briliyan->next->next = newNode;
	briliyan->next = newNode;

}

bool CircularLinkedList::search(int rollno, Node** triandri, Node** briliyan) {
	*triandri = LAST->next;
	*briliyan = LAST->next;
	while (*briliyan != LAST) {
		if (rollno == (*briliyan)->rollNumber) {
			return true;
		}
		*triandri = *briliyan;
		*briliyan = (*briliyan)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}

bool CircularLinkedList::delNode() { //write your answer here
}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': 
				obj.addNode();
				break;
			case '2': 
				obj.listEmpty();
				break;
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
} 