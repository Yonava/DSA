#include <iostream>

using namespace std;

#define LOG(item) cout << item << endl << endl;

class StudentIDArray {

  private:
    const static int SIZE_OF_ARRAY = 10;
    int studentIDs[SIZE_OF_ARRAY];

  public:
    // unparameterized
    StudentIDArray() {
      this->resetArray();
    }

    // adds studentID to the end of array
    void push(int studentID) {
      for (int i = 0; i < SIZE_OF_ARRAY; i++) {
        if (this->studentIDs[i] == -1) {
          this->studentIDs[i] = studentID;
          return;
        }
      }
    }

    // removes studentID on the end LIFO
    void pop() {
      for (int i = SIZE_OF_ARRAY; i >= 0; i--) {
        if (this->studentIDs[i] != -1) {
          this->studentIDs[i] = -1;
          return;
        }
      }
    }

    // calls when StudentIDArray is instantiated, or when array needs to be cleared
    void resetArray() {
      for (int i = 0; i < SIZE_OF_ARRAY; i++) {
        this->studentIDs[i] = -1;
      }
    }

    // returns studentID for given index
    int getStudentID(int n) {
      return this->studentIDs[n];
    }

    // returns index when given a studentID, returns -1 if no studentID matches
    int getIndexOfID(int studentID) {
      for (int i = 0; i < SIZE_OF_ARRAY; i++) {
        if (studentID == this->studentIDs[i]) {
          return i;
        }
      }
      return -1;
    }
};

int main() {

  StudentIDArray x = StudentIDArray();

  // x.resetArray();
  // x.push(4113);
  // x.push(1253);
  // x.push(9998);
  // LOG(x.getStudentID(0));
  // LOG(x.getStudentID(1));
  // LOG(x.getStudentID(2));
  // LOG(x.getIndexOfID(9998));
  // x.pop();
  // x.pop();
  // LOG(x.getStudentID(0));
  // LOG(x.getStudentID(1));
  // LOG(x.getStudentID(2));

  return 0;
}