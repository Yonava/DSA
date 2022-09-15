#pragma once
#include <string>
#include <iostream>

#define LOG(item) cout << item << endl;

using namespace std;


struct Student {
  string name = "Unoccupied";
  int id = 0;
};

class StudentIDArray {

  private:
    const static int SIZE_OF_ARRAY = 10;
    Student students[SIZE_OF_ARRAY];
    int indexTracker = 0;

  public:
    StudentIDArray();

    void display();

    // adds studentID to the end of array
    string push(Student student);

    int lengthOfStudentList();

    // removes studentID on the end LIFO
    string pop();

    // calls when StudentIDArray is instantiated, or when array needs to be cleared
    void resetArray();

    // returns student for given index
    string getStudentByIndex(int n);

    string overrideItemPos(Student student, int pos);

    // returns index when given a studentID, returns -1 if no studentID matches
    int getIndexOfID(int studentId);
};