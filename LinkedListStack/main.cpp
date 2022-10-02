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
}

int main()
{

	Student *s;
  	createStudent(s);

	// instanciates our stack
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
				createStudent(s);
				cout << stack->push(s) << endl;
				break;
			case 1:
				cout << stack->pop() << endl;
				break;
			case 2:
				stack->peek();
				break;
			case 3:
				cout << "Your Stack Has A Length Of: " << stack->size() << endl;
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
				delete stack;
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