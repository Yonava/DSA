#include "StudentIDArray.h"

int options() {

  	// UI that allows users to select from a menu of choices
  	int choice;
  	cout << "Select The Following" << endl;
  	cout << "0 - Push Item" << endl;
  	cout << "1 - Pop Item" << endl;
  	cout << "2 - Insert Item" << endl;
  	cout << "3 - Remove Item" << endl;
  	cout << "4 - Override Item" << endl;
  	cout << "4 - Get Item By Index" << endl;
  	cout << "6 - Get Index Of Student By Student ID" << endl;
  	cout << "7 - Display Contents of Array" << endl;
	cout << "8 - Display Length of Array" << endl;
  	cout << "9 - Exit Program" << endl;
  	cin >> choice;

 	return choice;
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

	while (running) {
		selectedOption = options();
		switch (selectedOption) {
			case 0:
				cout << "Enter Student ID: ";
				cin >> s.id;
				cout << "Student Name: ";
				cin >> s.name;
				cout << "Phone Number: ";
				cin >> s.phoneNum;
				cout << "Address: ";
				cin >> s.address;
				cout << x.push(s) << endl;
				break;
			case 1:
				cout << x.pop() << endl;
				break;
			case 2:
				cout << "Enter Student ID: ";
				cin >> s.id;
				cout << "Student Name: ";
				cin >> s.name;
				cout << "Phone Number: ";
				cin >> s.phoneNum;
				cout << "Address: ";
				cin >> s.address;
				cout << "Which Index: ";
				cin >> pos;
				cout << x.insert(s, pos) << endl;
				break;
			case 3:
				cout << "Enter Index: ";
				cin >> pos;
				cout << x.remove(pos) << endl;
				break;
			case 4:
				cout << "Enter Student ID: ";
				cin >> s.id;
				cout << "Student Name: ";
				cin >> s.name;
				cout << "Phone Number: ";
				cin >> s.phoneNum;
				cout << "Address: ";
				cin >> s.address;
				cout << "Which Index: ";
				cin >> pos;
				cout << x.overrideItemPos(s, pos) << endl;
				break;
			case 5:
				cout << "Enter Index: ";
				cin >> pos;
				cout << x.getStudentByIndex(pos) << endl;
				break;
			case 6:
				cout << "Enter A Student ID: ";
				cin >> id;
				cout << x.getIndexOfID(id) << endl;
				break;
			case 7:
				cout << "Here it is: " << endl;
				x.display();
				break;
			case 8:
				cout << "Your Array Has A Length Of: " << x.lengthOfStudentList() << endl;
				break;
			case 9:
				running = false;
				break;
			default:
				cout << "Input Unrecognized" << endl;
				break;
		}
	}

	return 0;
}