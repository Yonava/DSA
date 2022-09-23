#include "StudentIDArray.h"

StudentIDArray::StudentIDArray() {
  	resetArray();
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

void StudentIDArray::peek() {
	if (indexTracker == 0) {
		cout << "Stack is empty!" << endl;
	} else {
		Student s = students[indexTracker - 1];
		cout << s.name << " - " << s.id << " - " << s.address << " - " << s.phoneNum << endl;
	}
}