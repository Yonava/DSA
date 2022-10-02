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
  	cout << "5 - Get Item By Index" << endl;
  	cout << "6 - Get Index Of Student By Student ID" << endl;
  	cout << "7 - Display Contents of Array" << endl;
    cout << "8 - Display Length of Array" << endl;
    cout << "9 - Swap Two Students Position" << endl;
    cout << "10 - Reset Array" << endl;
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

  	// instantiates our array
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
			case 3:
				cout << "Enter Index: ";
				cin >> pos;
				cout << x.remove(pos) << endl;
				break;
			case 4:
				createStudent(s);
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
				cout << "Enter First Position: ";
				cin >> pos;
				cout << "Enter Second Position: ";
				cin >> pos2;
				cout << x.swap(pos, pos2) << endl;
				break;
			case 10:
				x.resetArray();
				cout << "Array Has Been Reset" << endl;
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