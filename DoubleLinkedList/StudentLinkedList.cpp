#include "DLL.h"

StudentLinkedList::StudentLinkedList(Student *student)
{
	Node *n = new Node;
	n->student = student;
	n->prev = nullptr;
	n->next = nullptr;
	this->head = n;
	this->tail = n;

	this->length = 1;
	this->pos = n;

	n = nullptr;
	delete n;
}

StudentLinkedList::~StudentLinkedList()
{
	Node *temp = this->head;
	while (temp->next != nullptr)
	{
		delete temp->student;
		delete temp->prev;
		temp = temp->next;
	}

	temp = nullptr;
	delete temp;
	delete this->tail;
}

int StudentLinkedList::getLength()
{
	return this->length + 1;
}

void StudentLinkedList::push(Student *student)
{
	Node *n = new Node;
	n->student = student;
	n->prev = this->tail;
	this->tail->next = n;
	this->tail = n;
	this->tail->next = nullptr;
	this->length++;
}

void StudentLinkedList::insert(Student *student, int pos) {
	Node *temp = this->head;
	int counter = 0;
	while (counter != pos)
	{
		temp = temp->next;
		counter++;
	}

	Node *n = new Node;
	n->student = student;

	// head
	if (temp->prev == nullptr)
	{
		n->next = temp;
		n->prev = nullptr;
		temp->prev = n;
		this->head = n;
	}

	// tail
	else if (temp->next == nullptr)
	{
		n->next = nullptr;
		n->prev = temp;
		temp->next = n;
		this->tail = n;
	}

	// body
	else
	{
		n->prev = temp->prev;
		n->next = temp;
		temp->prev->next = n;
		temp->prev = n;
	}
}

void StudentLinkedList::getStudentAtIndex(int pos) {
	Node *temp = this->head;
	int counter = 0;
	while (counter != pos)
	{
		temp = temp->next;
		counter++;
	}

	cout << temp->student->name << " - " << temp->student->address << " - " << temp->student->id << " - " << temp->student->phoneNum << endl;
}

void StudentLinkedList::remove(int pos)
{
	Node *temp = this->head;
	int counter = 0;
	while (counter != pos)
	{
		temp = temp->next;
		counter++;
	}

	// head
	if (temp->prev == nullptr)
	{
		temp->next->prev = nullptr;
		this->head = temp->next;
	}

	// tail
	else if (temp->next == nullptr)
	{
		temp->prev->next = nullptr;
		this->tail = temp->prev;
	}

	// body
	else
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
	}

	delete temp->student;
	this->length--;

	temp = nullptr;
	delete temp;
}

void StudentLinkedList::print()
{
	Node *temp = this->head;

	while (temp != nullptr)
	{
		cout << temp->student->name << " - " << temp->student->address << " - " << temp->student->id << " - " << temp->student->phoneNum << endl;
		temp = temp->next;
	}

	temp = nullptr;
	delete temp;
}

void StudentLinkedList::moveToStart() {
	this->pos = this->head;
}

void StudentLinkedList::moveToEnd() {
	this->pos = this->tail;
}

void StudentLinkedList::moveToPos(int pos) {
	Node *temp = this->head;
	int counter = 0;
	while (counter != pos)
	{
		temp = temp->next;
		counter++;
	}

	this->pos = temp;
}

void StudentLinkedList::currPos() {
	cout << "The node you are on is: " << this->pos->student->name << endl;
}