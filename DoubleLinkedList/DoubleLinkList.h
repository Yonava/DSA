#pragma once
#include <string>
#include <iostream>

using std::string;

struct Node {
	Node* prev;
	Node* next;
	int data;
};

struct Student {
    string name;
    int id;
    string phoneNum;
    string address;
};

class StudentLinkedList {

	private:

	public:

	StudentLinkedList();

	void insert(Student student);
	void remove(int index);


};


