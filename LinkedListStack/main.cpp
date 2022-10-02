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
	StudentLLStack *x = new StudentLLStack(s);

	int selectedOption;
	bool running = true;

	while (running)
	{
		selectedOption = options();
		cout << "------------------" << endl;
		switch (selectedOption)
		{
			case 0:
				createStudent(s);
				cout << x->push(s) << endl;
				break;
			case 1:
				cout << x->pop() << endl;
				break;
			case 2:
				x->peek();
				break;
			case 3:
				cout << "Your Stack Has A Length Of: " << x->size() << endl;
				break;
			case 4:
				if (x->empty()) {
					cout << "Stack is empty" << endl;
				} else {
					cout << "Stack is not empty" << endl;
				}
				break;
			case 5:
				cout << "Bye!" << endl;
				running = false;
				delete x;
				break;
			default:
				cout << "Input Unrecognized" << endl;
				break;
		}
	}

	return 0;
}