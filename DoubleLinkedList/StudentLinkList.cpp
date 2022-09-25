#include "DoubleLinkList.h"

StudentLinkedList::StudentLinkedList(Student* student)
{
	Node* n = new Node;
	n->student = student;
	n->prev = nullptr;
	head = n;
	tail = n;
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
	Node* n = new Node;
	n->student = student;
	n->prev = tail;
	tail->next = n;
	tail = n;
	tail->next = nullptr;
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