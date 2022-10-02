#include "StudentLLStack.h"

int options()
{
	// UI that allows users to select from a menu of choices
	int choice;
	cout << "------------------" << endl;
	cout << "Select The Following" << endl;
	cout << "0 - Push Item" << endl;
	cout << "1 - Pop Item" << endl;
	cout << "2 - Peek" << endl;
	cout << "3 - Length of Stack" << endl;
	cout << "4 - Is Empty?" << endl;
	cout << "5 - Exit Program" << endl;
	cin >> choice;

	return choice;
}

void createStudent(Student *s)
{
	cout << "Student Name: ";
	cin >> s->name;
	cout << "Enter Student ID: ";
	cin >> s->id;
	cout << "Phone Number: ";
	cin >> s->phoneNum;
	cout << "Address: ";
	cin >> s->address;
	cout << "------------------" << endl;
}

int main()
{
	Student *s = new Student();
  	createStudent(s);

	// instantiates our stack
	StudentLLStack *stack = new StudentLLStack(s);

	int selectedOption;
	bool running = true;

	while (running)
	{
		Student *newStudent = new Student;
		selectedOption = options();
		cout << "------------------" << endl;
		switch (selectedOption)
		{
			case 0:
				createStudent(newStudent);
				if (stack->push(newStudent)) {
					cout << newStudent->name + " Has Been Pushed On The Stack" << endl;
				} else {
					cout << "Item Couldn't Be Pushed." << endl;
				}
				break;
			case 1:
				if (stack->pop()) {
					cout << "Item Popped." << endl;
				} else {
					cout << "Popping The Last Item Would Destroy The Linked List!" << endl;
				}
				break;
			case 2:
				cout << stack->peek() << endl;
				break;
			case 3:
				cout << "Students In Stack: " << stack->size() << endl;
				break;
			case 4:
				if (stack->empty()) {
					cout << "Stack is empty" << endl;
				} else {
					cout << "Stack is not empty" << endl;
				}
				break;
			case 5:
				cout << "Bye!" << endl;
				running = false;
				break;
			default:
				cout << "Input Unrecognized" << endl;
				break;
		}

		newStudent = nullptr;
		delete newStudent;
	}

	s = nullptr;
	stack = nullptr;
	delete s;
	delete stack;
	return 0;
}