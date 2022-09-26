#include "DLL.h"

StudentLinkedList::StudentLinkedList(Student* student)
{
    Node* n = new Node;
    n->student = student;
    n->prev = nullptr;
    n->next = nullptr;
    this->head = n;
    this->tail = n;

    n = nullptr;
    delete n;
}

StudentLinkedList::~StudentLinkedList() 
{
    Node* temp = this->head;
    while (temp->next != nullptr) {
        delete temp->student;
        delete temp->prev;
        temp = temp->next;
    }

    temp = nullptr;
    delete temp;
	delete this->head;
	delete this->tail;
}

int StudentLinkedList::getLength()
{
    return this->length;
}

void StudentLinkedList::insert(Student* student)
{
    Node* n = new Node;
    n->student = student;
    n->prev = this->tail;
    this->tail->next = n;
    this->tail = n;
    this->tail->next = nullptr;
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
	this->head = temp->next;
  }

  // tail
  else if (temp->next == nullptr) {
    temp->prev->next = nullptr;
	this->tail = temp->prev;
  }

  // body
  else {
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
  }

  delete temp->student;

  temp = nullptr;
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

    temp = nullptr;
    delete temp;
}