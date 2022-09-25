#include "DoubleLinkList.h"

StudentLinkedList::StudentLinkedList(Student* student)
{
	Node* n = new Node;
	n->student = student;
	n->prev = nullptr;
	n->next = nullptr;
	this->head = n;
	this->tail = n;
}

StudentLinkedList::~StudentLinkedList() 
{
	Node* temp = this->head;
	while (temp->next != nullptr) {
		delete temp->prev;
		temp = temp->next;
	}
}

void StudentLinkedList::insert(Student* student)
{
	// prints passed in students name
	cout << this->head->student->name << endl;

	Node* n = new Node;
	n->student = student;
	n->prev = this->tail;
	this->tail->next = n;
	this->tail = n;
	this->tail->next = nullptr;

	// prints passed in students name
	cout << this->head->student->name << endl;
}

void StudentLinkedList::remove(int pos)
{
  Node *temp = this->head;
  int counter = 0;
  while (counter != pos) {
    temp = temp->next;
    counter++;
  }

  // head
  if (temp->prev == nullptr) {
    temp->next->prev = nullptr;
  }

  // tail
  else if (temp->next == nullptr) {
    temp->prev->next = nullptr;
  }

  // body
  else {
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
  }

  delete temp;
  
}

void StudentLinkedList::print()
{
	Node *temp = this->head;

	while (temp != nullptr)
	{
		cout << temp->student->name << " - " << temp->student->pronouns << endl;
		temp = temp->next;
	}
}