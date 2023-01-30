#pragma once
#include <vector>

using namespace std;

template <class T>
class Stack
{
private:
  vector<T> stack;
  int top;

public:
  Stack();
  void push(T);
  T pop();
  T peek();
  bool isEmpty();
  void print();
};