#include <iostream>
#include <string>

using namespace std;

#define LOG(item) cout << item << endl;

struct Student {
  string name = "Unoccupied";
  int id = 0;

  // Student(int id, string name) {
  //   Student.id = id,
    
  // }
};

class StudentIDArray {

  private:
    const static int SIZE_OF_ARRAY = 10;
    Student students[SIZE_OF_ARRAY];
    int indexTracker = 0;

  public:
    // unparameterized
    StudentIDArray() {
      resetArray();
    }

    void display() {
      for (int i = 0; i < SIZE_OF_ARRAY; i++) {
        string assignment = students[i].name == "Unoccupied" ? " Is Unassigned." : " Is Assigned To " + students[i].name + " - " + to_string(students[i].id);
        cout << "Index " << i << assignment << endl;
      }
    }

    // adds studentID to the end of array
    string push(Student student) {
      if (indexTracker == 9) return "Array Maxed Out";
      students[indexTracker] = student;
      indexTracker++;
      return "Added Student";
    }

    int lengthOfStudentList() {
      return indexTracker;
    }

    // removes studentID on the end LIFO
    string pop() {
      if (indexTracker == 0) return "No Items To Pop";
      indexTracker--;
      return "Popped";
    }

    // calls when StudentIDArray is instantiated, or when array needs to be cleared
    void resetArray() {
      indexTracker = 0;
    }

    // returns student for given index
    string getStudentByIndex(int n) {
      if (n >= indexTracker) return "Index " + to_string(n) + " Is Out of Range"; 
      return students[n].name + " - " + to_string(students[n].id);
    }

    string overrideItemPos(Student student, int pos) {
      if (pos >= indexTracker) return "Inputted position of " + to_string(pos) +  " out of range";
      students[pos] = student;
      return "Success!";
    }

    // returns index when given a studentID, returns -1 if no studentID matches
    int getIndexOfID(int studentId) {
      for (int i = 0; i < SIZE_OF_ARRAY; i++) {
        if (studentId == students[i].id) {
          return i;
        }
      }
      return -1;
    }
};

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