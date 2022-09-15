#include "StudentIDArray.h"

int options() {
  int choice;
  cout << "Select The Following" << endl;
  cout << "0 - Push Item" << endl;
  cout << "1 - Pop Item" << endl;
  cout << "2 - Override Item" << endl;
  cout << "3 - Get Item By Index" << endl;
  cout << "4 - Get Index Of Student By Student ID" << endl;
  cout << "5 - Display Contents of Array" << endl;
  cout << "6 - Exit Program" << endl;
  cin >> choice;

  return choice;
}

int main() {

  StudentIDArray x = StudentIDArray();
  Student s;
  
  int selectedOption;
  bool running = true;

  string name;
  int id;
  int pos;

  while (running) {
    selectedOption = options();
    switch (selectedOption) {
      case 0:
        cout << "Enter Student ID: ";
        cin >> s.id;
        cout << "Student Name: ";
        cin >> s.name;
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
        cout << "Which Index? " << x.lengthOfStudentList() << " Indices Available: ";
        cin >> pos;
        cout << x.overrideItemPos(s, pos) << endl;
        break;
      case 3:
        cout << "Enter Index: ";
        cin >> pos;
        cout << x.getStudentByIndex(pos) << endl;
        break;
      case 4:
        cout << "Enter A Student ID: ";
        cin >> id;
        cout << x.getIndexOfID(id) << endl;
        break;
      case 5:
        cout << "Here it is: " << endl;
        x.display();
        break;
      case 6:
        running = false;
        break;
      default:
        cout << "Input Unrecognized" << endl;
        break;
    }
  }

  return 0;
}