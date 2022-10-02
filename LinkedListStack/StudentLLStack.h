/*
	Authored By Yona Voss-Andreae,
	ID #2073993 - yona.voss-andreae@snhu.edu,
	CS217 Assignment 4, Array-Based Stack
*/

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
};

struct Node {
	Node *prev;
	Student *student;
};

class StudentLLStack {
	private:
		int itemsInList = 0;
		Node *topItem;
	public:
		// constructor takes in first item to setup LL
		StudentLLStack(Student *s);

		// destructor to free pointers from memory
		~StudentLLStack();

		// adds item to the stack, returns true if successful
		bool push(Student *s);

		// removes last item from stack, returns true if successful
		bool pop();

		// shows user the top item in the stack
		string peek();

		// returns number of items inside the stack
		int size();
		
		// returns true if stack is empty, otherwise false
		bool empty();
};