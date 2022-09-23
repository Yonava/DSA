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

		// takes a student and returns a string to indicate success or failure
		string push(Student student);

		// returns the number of occupied indices in array
		int lengthOfStudentList();

		// removes last student in array
		string pop();

    // returns top of stack
    void peek();

		// calls when StudentIDArray is instantiated, or when array needs to be cleared
		void resetArray();
};