#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Student {
    string name;
    string id;
    string phoneNum;
    string address;
};

class StudentStack {

  	private:
    	const static int SIZE_OF_ARRAY = 10;
    	Student students[SIZE_OF_ARRAY];
    	int topItemIndex = -1;
		int lengthOfList = 0;

	public:
		// takes a student and returns a string to indicate success or failure
		string push(Student student);

		// returns the number of occupied indices in array
		int size();

		// removes last student in array
		string pop();

		// returns top of stack
		void peek();

		// when array needs to be cleared
		void resetArray();

		// returns true if empty or false if not empty
		bool empty();

		// returns true if full or false if not full
		bool full();
};