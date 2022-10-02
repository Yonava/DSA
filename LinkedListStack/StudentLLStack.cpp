#include "StudentLLStack.h"

StudentLLStack::StudentLLStack(Student *s) {
	Node *n = new Node();
	n->student = s;
	n->prev = nullptr;
	this->topItem = n;
	itemsInList++;
}

StudentLLStack::~StudentLLStack() {

}

bool StudentLLStack::push(Student *s) {
	Node *n = new Node();
	n->student = s;
	n->prev = this->topItem;
	this->topItem = n;
	itemsInList++;
}

bool StudentLLStack::pop() {
	Node *temp = this->topItem;
	this->topItem = this->topItem->prev;
	itemsInList--;
	delete temp;
}

string StudentLLStack::peek() {
	Student *s = this->topItem->student;
	string str = "Name: " + s->name + " / ID: " + s->id + " / Address: " + s->address + " / Phone #: " + s->phoneNum;
	return str;
}

int StudentLLStack::size() {
	return itemsInList;
}

bool StudentLLStack::empty() {
	return this->topItem == nullptr;
}

