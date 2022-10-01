#include "StudentStack.h"

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
	cout << "4 - Reset Stack" << endl;
	cout << "5 - Is Empty?" << endl;
	cout << "6 - Is Full?" << endl;
	cout << "7 - Exit Program" << endl;
	cin >> choice;

	return choice;
}

void createStudent(Student &s)
{
	cout << "Student Name: ";
	cin >> s.name;
	cout << "Enter Student ID: ";
	cin >> s.id;
	cout << "Phone Number: ";
	cin >> s.phoneNum;
	cout << "Address: ";
	cin >> s.address;
}

int main()
{

	// instanciates a studentidarray object
	StudentStack x = StudentStack();
	Student s;

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
				cout << x.push(s) << endl;
				break;
			case 1:
				cout << x.pop() << endl;
				break;
			case 2:
				x.peek();
				break;
			case 3:
				cout << "Your Stack Has A Length Of: " << x.size() << endl;
				break;
			case 4:
				cout << "Stack Reset." << endl;
				x.resetStack();
				break;
			case 5:
				if (x.empty()) {
					cout << "Stack is empty" << endl;
				} else {
					cout << "Stack is not empty" << endl;
				}
				break;
			case 6:
				if (x.full()) {
					cout << "Stack is full" << endl;
				} else {
					cout << "Stack is not full" << endl;
				}
				break;
			case 7:
				cout << "Bye!" << endl;
				running = false;
				break;
			default:
				cout << "Input Unrecognized" << endl;
				break;
		}
	}

	return 0;
}