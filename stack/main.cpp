#include "StudentIDArray.h"

int options() {

  	// UI that allows users to select from a menu of choices
  	int choice;
  	cout << "Select The Following" << endl;
  	cout << "0 - Push Item" << endl;
  	cout << "1 - Pop Item" << endl;
    cout << "2 - Peek" << endl;
    cout << "8 - Length of Stack" << endl;
    cout << "10 - Reset Stack" << endl;
  	cout << "11 - Exit Program" << endl;
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
				createStudent(s);
				cout << "Which Index: ";
				cin >> pos;
				cout << x.insert(s, pos) << endl;
				break;
			case 8:
				cout << "Your Array Has A Length Of: " << x.lengthOfStudentList() << endl;
				break;
			case 11:
				running = false;
				break;
			default:
				cout << "Input Unrecognized" << endl;
				break;
		}
	}

	return 0;
}