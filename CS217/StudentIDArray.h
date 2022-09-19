#pragma once
#include <string>
#include <iostream>

#define LOG(item) cout << item << endl;

using namespace std;

struct Student {
    string name;
    int id;
    string phoneNum;
    string address;
};

class StudentIDArray {

  	private:
    	const static int SIZE_OF_ARRAY = 10;
    	Student students[SIZE_OF_ARRAY];
    	int indexTracker = 0;

	public:
		StudentIDArray();

		// prints out the contents of array
		void display();

		// adds studentID to the end of array
		string push(Student student);

		// inserts item into array at specified position
		string insert(Student student, int pos);

		// removes student at specified position
		string remove(int pos);

		// returns the number of occupied indices in array
		int lengthOfStudentList();

		// removes studentID on the end LIFO
		string pop();

		// calls when StudentIDArray is instantiated, or when array needs to be cleared
		void resetArray();

		// returns student for given index
		string getStudentByIndex(int n);

		// takes new student along with a currently occupied index and replaces the previous student with the new student
		string overrideItemPos(Student student, int pos);

		// returns index when given a studentID, returns -1 if no studentID matches
		int getIndexOfID(int studentId);
};