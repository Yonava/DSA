#include "StudentIDArray.h"

int options() {

  	// UI that allows users to select from a menu of choices
  	int choice;
  	cout << "Select The Following" << endl;
  	cout << "0 - Push Item" << endl;
  	cout << "1 - Pop Item" << endl;
    cout << "2 - Peek" << endl;
    cout << "3 - Length of Stack" << endl;
    cout << "4 - Reset Stack" << endl;
  	cout << "5 - Exit Program" << endl;
  	cin >> choice;

 	return choice;
}

void createStudent(Student &s) {
	cout << "Student Name: ";
	cin >> s.name;
	cout << "Enter Student ID: ";
	cin >> s.id;
	cout << "Phone Number: ";
	cin >> s.phoneNum;
	cout << "Address: ";
	cin >> s.address;
}

int main() {

  	// instanciates a studentidarray object
  	StudentIDArray x = StudentIDArray();
  	Student s;
  
  	int selectedOption;
  	bool running = true;

    string name;
    int id;
    string phoneNum;
    string address;

    int pos;
    int pos2;

	while (running) {
		selectedOption = options();
		switch (selectedOption) {
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
				cout << "Your Stack Has A Length Of: " << x.lengthOfStudentList() << endl;
				break;
			case 4:
				cout << "Stack Reset." << endl;
				x.resetArray();
				break;
			case 5:
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