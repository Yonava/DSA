#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <fstream>

using namespace std;

const unsigned int DEFAULT_SIZE = 179;

struct Course
{
  string courseId;
  string title;
  vector<string> prereqs;
};

class HashTable
{
private:
  struct Node
  {
    Course course;
    unsigned int key;
    Node *next;

    Node()
    {
      key = UINT_MAX;
      next = nullptr;
    }

    Node(Course aCourse) : Node()
    {
      course = aCourse;
    }

    Node(Course aCourse, unsigned int aKey) : Node(aCourse)
    {
      key = aKey;
    }
  };

  vector<Node> nodes;

  unsigned int tableSize = 179;

  unsigned int hash(string key);

public:
  HashTable();
  virtual ~HashTable();
  void Insert(Course course);
  void PrintAll();
  void Remove(string courseId);
  Course Search(string courseId);
};