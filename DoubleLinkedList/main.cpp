#include <iostream>
#include <string>

using std::string;

struct Node {
	Node* prev;
	Node* next;
	int data;
};

void PrintForward(Node* head);
void PrintReverse(Node* tail);

int main() {

	Node* head;
	Node* tail;
	Node* n;

	n = new Node;
	n->data = 1;
	n->prev = NULL;
	head = n;
	tail = n;

	n = new Node;
	n->data = 2;
	n->prev = tail;
	tail->next = n;
	tail = n;

	n = new Node;
	n->data = 3;
	n->prev = tail;
	tail->next = n;
	tail = n;

	n = new Node;
	n->data = 4;
	n->prev = tail;
	tail->next = n;
	tail = n;

	tail->next = NULL;	

	// PrintForward(head);
	PrintReverse(tail);
	
	return 0;
}

void PrintForward(Node* head) {
	Node* temp = head;

	while(temp != NULL) {
		std::cout << temp->data << std::endl;
		temp = temp->next;
	}
}

void PrintReverse(Node* tail) {
	Node* temp = tail;

	while(temp != NULL) {
		std::cout << temp->data << std::endl;
		temp = temp->prev;
	}
}
