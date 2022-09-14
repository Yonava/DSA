#include <iostream>
#include <string>

using namespace std;

#define LOG(item) cout << item << endl << endl;

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
        if (students[i].name == "Unoccupied") {
          cout << "Index " << i << " Is Unassigned." << endl;
        }
        else {
          cout << students[i].name << " - " << students[i].id << endl;
        }
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
    Student getStudentByIndex(int n) {
      return students[n];
    }

    string insertItemPos(Student student, int pos) {
      if (pos >= SIZE_OF_ARRAY) return "Inputted position of " + to_string(pos) +  " out of range";
      students[pos] = student;
      return "Success!";
    }

    // returns index when given a studentID, returns -1 if no studentID matches
    int getIndexOfID(Student studentID) {
      for (int i = 0; i < SIZE_OF_ARRAY; i++) {
        if (studentID.id == students[i].id) {
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
  cout << "4 - Get Item By Student ID" << endl;
  cout << "5 - Exit Program" << endl;
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
        cout << "Here it is: " << endl;
        x.display();
        break;
      case 2:
      case 3:
      case 4:
      case 5:
        running = false;
        break;
      default:
        cout << "Input Unrecognized" << endl;
        break;
    }
  }




  return 0;
}