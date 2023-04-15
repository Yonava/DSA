#include "HashTable.h"

const unsigned int DEFAULT_SIZE = 179;

struct Course {
  string courseId;
  string title;
  vector<Course> prereqs;
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

  unsigned int tableSize = DEFAULT_SIZE;

  unsigned int hash(int key);

public:
  HashTable();
  virtual ~HashTable();
  void Insert(Course course);
  void PrintAll();
  void Remove(string courseId);
  Course Search(string courseId);
};

HashTable::HashTable()
{
  nodes.resize(tableSize);
}

/**
 * Destructor
 */
HashTable::~HashTable()
{
  // erase nodes beginning
  nodes.erase(nodes.begin());
}

unsigned int HashTable::hash(int key)
{
  // prime number used for optimal spread
  key *= 2654435761;
  return key % tableSize;
}

void HashTable::Insert(Course course)
{
  // create the key for the given bid
  unsigned int key = hash(atoi(course.courseId.c_str()));

  // retrieve node using key
  Node *node = &nodes[key];

  // if no entry found for the key
  if (node->key == UINT_MAX)
  {
    // assign this node to the key position
    node->key = key;
    node->course = course;
  }
  // else if node is not used
  else if (node->key == key)
  {
    // assign this node to the key position
    node->key = key;
    node->course = course;
  }
  // assign old node key to UNIT_MAX, set to key, set old node to bid and old node next to null pointer
  else
  {
    Node *oldNode = node;
    node->key = key;
    node->course = course;
    node->next = nullptr;
    // while node next not equal to null pointer
    while (node->next != nullptr)
    {
      // node is equal to next node
      node = node->next;
    }
    // add old node to end
    node->next = oldNode;
  }
}

void displayBid(Course course)
{
  cout << course.courseId << ": " << course.title << " | ";
  for (int i = 0; i < course.prereqs.size(); i++)
  {
    cout << course.prereqs[i].courseId << " ";
  }
  return;
}

void HashTable::PrintAll()
{
  for (int i = 0; i < nodes.size(); i++)
  {
    if (nodes[i].key != UINT_MAX)
    {
      displayBid(nodes[i].course);
    }
    if (nodes[i].next != nullptr)
    {
      displayBid(nodes[i].next->course);
    }
  }
}

void HashTable::Remove(string bidId)
{
  // set key equal to hash atoi bidID cstring
  unsigned int key = hash(atoi(bidId.c_str()));
  
  // if node key is equal to key
  if (nodes[key].key == key)
  {
    // set node key to UINT_MAX
    nodes[key].key = UINT_MAX;
  }
}

Course HashTable::Search(string courseId)
{
  Course course;

  // create the key for the given bid
  // if entry found for the key
  // return node bid

  unsigned int key = hash(atoi(courseId.c_str()));

  if (nodes[key].key == key)
  {
    return nodes[key].course;
  }

  // if no entry found for the key
  // return bid

  if (nodes[key].key == UINT_MAX)
  {
    return course;
  }

  // while node not equal to nullptr
  // if the current node matches, return it
  // node is equal to next node

  Node *node = &nodes[key];
  while (node != nullptr)
  {
    if (node->course.courseId == courseId)
    {
      return node->course;
    }
    node = node->next;
  }

  return course;
}


void loadCourses(string path, HashTable *hashTable)
{

}
