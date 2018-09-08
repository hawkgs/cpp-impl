#include <iostream>
using namespace std;

struct Node {
	public:
		Node *next;
		int value;
		Node(int v);
};

Node::Node(int v) {
	value = v;
	next = NULL;
}

class LinkedList {
	public:
		Node *head;
		Node *tail;
		LinkedList();
		~LinkedList();
		int getSize();
		void add(int value);
		int pop();
		void merge(LinkedList *list);
		void sort();
	private:
		int size;
};

LinkedList::LinkedList() {
	size = 0;
	head = NULL;
	tail = NULL;
}

LinkedList::~LinkedList() {
	Node *curr = head;
	Node *next;

	while (curr) {
		next = curr->next;
		// cout << "deleting: " << curr << "; with val: " << curr->value << ";" << endl;
		delete curr;
		curr = next;
	}
}

int LinkedList::getSize() {
	return size;
}

void LinkedList::add(int value) {
	Node *newNode = new Node(value);

	if (!head) {
		head = newNode;
	}
	else if (!head->next) {
		head->next = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	size++;
}

int LinkedList::pop() {
	Node *pop = head;
	Node *prev = NULL;

	while (pop) {
		if (!pop->next) {
			if (prev) {
				prev->next = NULL;
			}
			tail = prev;
			int val = pop->value;
			delete pop;
			size--;
			return val;
		}
		prev = pop;
		pop = pop->next;
	}
	return -1;
}

void LinkedList::merge(LinkedList *list) {
	if (!list->head) {
		return;
	}

	Node *curr = list->head;

	while (curr) {
		this->add(curr->value);
		curr = curr->next;
	}
}

void LinkedList::sort() {
	Node *prev;
	Node *curr;

	for (int i = this->getSize(); i > 0; i--) {
		prev = head;
		curr = head->next;

		for (int j = 0; j < i - 1; j++) {
			if (prev->value > curr->value) {
				curr->value += prev->value;
				prev->value = curr->value - prev->value;
				curr->value -= prev->value;
			}
			prev = curr;
			curr = curr->next;
		}
	}
}

void printLinkedListValues(LinkedList *list) {
	Node *curr = list->head;

	do {
		cout << curr->value << endl;
		curr = curr->next;
	} while (curr);
}

int main() {
	LinkedList list;

	list.add(2);
	list.add(1);
	list.add(4);
	list.add(3);

	LinkedList list2;

	list2.add(7);
	list2.add(5);
	list2.add(6);

	list.merge(&list2);
	list.sort();

	printLinkedListValues(&list);
	cout << "Size: " << list.getSize();

	// cout << list->pop() << endl;
	// cout << list->pop() << endl;
	// cout << list->pop() << endl;
	// cout << list->pop() << endl;

	cout << endl << "end";
	return 0;
}
