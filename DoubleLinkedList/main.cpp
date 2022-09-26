#include "DLL.h"

int options()
{
    // UI that allows users to select from a menu of choices
    int choice;
    cout << "Select The Following" << endl;
    cout << "0 - Push Item" << endl;
    cout << "1 - Remove Item" << endl;
    cout << "2 - Length of Stack" << endl;
    cout << "3 - Print" << endl;
    cout << "4 - Get Student By Index" << endl;
	cout << "5 - Insert Item" << endl;
	cout << "6 - Exit" << endl;
	cout << "7 - Move To Start" << endl;
	cout << "8 - Move To End" << endl;
	cout << "9 - Move To Pos" << endl;
	cout << "10 - Display Current Pos" << endl;
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
    cout << "Pronouns: ";
    cin >> s->pronouns;
}

int main()
{

    Student *s = new Student;
    createStudent(s);
    StudentLinkedList *list = new StudentLinkedList(s);

    int pos;

    bool running = true;
    while (running)
    {
        Student *newStudent = new Student;
        int option = options();
        switch (option)
        {
			case 0:
				cout << "Enter Student: " << endl;
				createStudent(newStudent);
				list->push(newStudent);
				break;
			case 1:
				cout << "Enter a Position: ";
				cin >> pos;
				list->remove(pos);
				break;
			case 2:
				cout << list->getLength() << endl;
				break;
			case 3:
				list->print();
				break;
			case 4:
				cout << "Enter a Position: ";
				cin >> pos;
				list->getStudentAtIndex(pos);
				break;
			case 5:
				cout << "Enter a Position: ";
				cin >> pos;
				cout << "Enter Student: " << endl;
				createStudent(newStudent);
				list->insert(newStudent, pos);
				break;
			case 6:
				running = false;
				break;
			case 7:
				cout << "Moved Pos to Head" << endl;
				list->moveToStart();
				break;
			case 8:
				cout << "Moved Pos to Tail" << endl;
				list->moveToEnd();
				break;
			case 9:
				cout << "Enter a Position: " << endl;
				cin >> pos;
				list->moveToPos(pos);
				cout << "Moved!" << endl;
				break;
			case 10:
				list->currPos();
				break;
        }
        newStudent = nullptr;
        delete newStudent;
    }

    s = nullptr;
    delete s;

    delete list;

    return 0;
}