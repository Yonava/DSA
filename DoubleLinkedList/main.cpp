#include "DLL.h"

int options()
{
    // UI that allows users to select from a menu of choices
    int choice;
    cout << "Select The Following" << endl;
    cout << "0 - Push Item" << endl;
    cout << "1 - Pop Item" << endl;
    cout << "2 - Length of Stack" << endl;
    cout << "3 - Print" << endl;
    cout << "4 - Exit Program" << endl;
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
            list->insert(newStudent);
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
            running = false;
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