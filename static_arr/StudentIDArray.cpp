#include "StudentIDArray.h"

StudentIDArray::StudentIDArray() {
  	resetArray();
}

void StudentIDArray::display() {
  	for (int i = 0; i != indexTracker; i++) {
    	string assignment = " Is Assigned To " + students[i].name + " - " + to_string(students[i].id) + " - Phone #: " + students[i].phoneNum + " - Address: " + students[i].address;
    	cout << "Index " << i << assignment << endl;
  	}
}

string StudentIDArray::push(Student student) {
  	if (indexTracker == 9) return "Array Maxed Out";
  	students[indexTracker] = student;
  	indexTracker++;
  	return "Added Student";
}

string StudentIDArray::insert(Student student, int pos) {
  	if (pos > indexTracker) return "Out of Range, Try Pushing Instead";
  	for (int i = indexTracker; i > pos; i--) {
    	students[i] = students[i - 1];
  	}
  	students[pos] = student;
  	indexTracker++;
  	return "Item Successfully Inserted";
}

string StudentIDArray::remove(int pos) {
	if (!(pos > -1 && pos < indexTracker)) return "Cannot Remove Undefined";
	indexTracker--;
	for (int i = pos; i < indexTracker; i++) {
		students[i] = students[i + 1];
	}
	return "Removed Item";
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

string StudentIDArray::swap(int pos1, int pos2) {
	if (pos1 >= indexTracker || pos2 >= indexTracker) return "Position Out of Range";
	else if (pos1 < 0 || pos2 < 0) return "Positions Cannot Be Negative";
	Student temp = students[pos1];
	students[pos1] = students[pos2];
	students[pos2] = temp;
	return "Items Successfully Swapped";
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