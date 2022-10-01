#include "StudentStack.h"

string StudentStack::push(Student student) {
  	if (full()) return "Array Maxed Out";
  	students[topItemIndex + 1] = student;
  	topItemIndex++;
  	return "Added Student";
}

int StudentStack::size() {
	lengthOfList = topItemIndex + 1;
  	return lengthOfList;
}

string StudentStack::pop() {
  	if (empty()) return "No Items To Pop";
  	topItemIndex--;
  	return "Popped";
}

bool StudentStack::empty() {
	return topItemIndex == -1;
}

bool StudentStack::full() {
	return topItemIndex == (SIZE_OF_ARRAY - 1);
}

void StudentStack::resetArray() {
  	topItemIndex = -1;
}

void StudentStack::peek() {
	if (empty()) {
		cout << "Stack is empty!" << endl;
	} else {
		Student s = students[topItemIndex];
		cout << s.name << " - " << s.id << " - " << s.address << " - " << s.phoneNum << endl;
	}
}