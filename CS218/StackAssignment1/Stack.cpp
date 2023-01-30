#include "Stack.h"

// constructor
template <class T>
Stack<T>::Stack()
{
  top = -1;
}

// push function
template <class T>
void Stack<T>::push(T item)
{
  stack.push_back(item);
  top++;
}

// pop function

template <class T>
T Stack<T>::pop()
{
  T item = stack[top];
  stack.pop_back();
  top--;
  return item;
}

// peek function
template <class T>
T Stack<T>::peek()
{
  return stack[top];
}

// isEmpty function
template <class T>
bool Stack<T>::isEmpty()
{
  return (top == -1);
}

// print function
template <class T>
void Stack<T>::print()
{
  for (int i = top; i >= 0; i--)
  {
    cout << stack[i] << endl;
  }
}