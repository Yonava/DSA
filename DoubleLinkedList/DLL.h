#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Student
{
	string name;
	string id;
	string phoneNum;
	string address;
	string pronouns;
};

struct Node
{
	Node *prev;
	Node *next;
	Student *student;
};

class StudentLinkedList
{

private:
	Node *tail;
	Node *head;
	Node *pos;
	int length;

public:
	StudentLinkedList(Student *student);
	~StudentLinkedList();

	void push(Student *student);
	void insert(Student *student, int pos);
	void remove(int index);

	void getStudentAtIndex(int pos);

	int getLength();

	void print();

	void moveToStart();
	void moveToEnd();
	void moveToPos(int pos);
	void currPos();
};
