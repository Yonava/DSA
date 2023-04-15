#include "HashTable.h"

unsigned int hashString(const std::string &str, unsigned int seed = 0)
{
  unsigned int hash = seed;
  for (char c : str)
  {
    // 31 is commonly used as a magic number for hashing
    hash = (hash * 31) + c;
  }
  return hash;
}

HashTable::HashTable()
{
  nodes.resize(tableSize);
}

HashTable::~HashTable()
{
  // erase nodes beginning
  nodes.erase(nodes.begin());
}

unsigned int HashTable::hash(string key)
{
  return hashString(key) % tableSize;
}

void HashTable::Insert(Course course)
{
  // create the key for the given bid
  unsigned int key = hash(course.courseId);

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
  cout << course.courseId << ", " << course.title << endl;
}

void HashTable::PrintAll()
{
  Sort();
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

void HashTable::Sort()
{
  // sort nodes by course id
  sort(nodes.begin(), nodes.end(), [](Node a, Node b)
       { return a.course.courseId < b.course.courseId; });
}

void HashTable::Remove(string courseId)
{
  unsigned int key = hash(courseId);

  if (nodes[key].key == key)
  {
    nodes[key].key = UINT_MAX;
  }
}

Course HashTable::Search(string courseId)
{
  Course course;

  unsigned int key = hash(courseId);

  if (nodes[key].key == key)
  {
    return nodes[key].course;
  }

  if (nodes[key].key == UINT_MAX)
  {
    return course;
  }

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
