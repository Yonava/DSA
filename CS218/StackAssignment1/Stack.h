#pragma once

#include <string>
#include <fstream>
#include <iostream>
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
    void push(T item);
    int size();
    T pop();
    T peek();
    bool isEmpty();
    void print();
};

template <class T>
Stack<T>::Stack()
{
  top = -1;
}

template <class T>
void Stack<T>::push(T item)
{
  stack.push_back(item);
  top++;
}

template <class T>
int Stack<T>::size() {
  return stack.size();
}

template <class T>
T Stack<T>::pop()
{
  T item = stack[top];
  stack.pop_back();
  top--;
  return item;
}

template <class T>
T Stack<T>::peek()
{
  return stack[top];
}

template <class T>
bool Stack<T>::isEmpty()
{
  return (top == -1);
}

template <class T>
void Stack<T>::print()
{
  for (int i = top; i >= 0; i--)
  {
    cout << stack[i] << endl;
  }
}