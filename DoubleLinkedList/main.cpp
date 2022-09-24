#include <iostream>
#include <string>

using std::string;

int main() {

	struct Node {
		Node* prev;
		Node* next;
		int data;
	};

	Node* head;
	Node* tail;
	Node* n;

	n = new Node;
	
	n->data = 5;

}