#include "StudentIDArray.h"

StudentIDArray::StudentIDArray() {
  resetArray();
}

void StudentIDArray::display() {
  for (int i = 0; i < SIZE_OF_ARRAY; i++) {
    string assignment = students[i].name == "Unoccupied" ? " Is Unassigned." : " Is Assigned To " + students[i].name + " - " + to_string(students[i].id);
    cout << "Index " << i << assignment << endl;
  }
}

string StudentIDArray::push(Student student) {
  if (indexTracker == 9) return "Array Maxed Out";
  students[indexTracker] = student;
  indexTracker++;
  return "Added Student";
}

int StudentIDArray::lengthOfStudentList() {
  return indexTracker;
}

string StudentIDArray::pop() {
  if (indexTracker == 0) return "No Items To Pop";
  indexTracker--;
  return "Popped";
}

void StudentIDArray::resetArray() {
  indexTracker = 0;
}

string StudentIDArray::getStudentByIndex(int n) {
  if (n >= indexTracker) return "Index " + to_string(n) + " Is Out of Range"; 
  return students[n].name + " - " + to_string(students[n].id);
}

string StudentIDArray::overrideItemPos(Student student, int pos) {
  if (pos >= indexTracker) return "Inputted position of " + to_string(pos) +  " out of range";
  students[pos] = student;
  return "Success!";
}

int StudentIDArray::getIndexOfID(int studentId) {
  for (int i = 0; i < SIZE_OF_ARRAY; i++) {
    if (studentId == students[i].id) {
      return i;
    }
  }
  return -1;
}