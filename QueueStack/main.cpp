/*
  Authored By Yona Voss-Andreae,
  ID #2073993 - yona.voss-andreae@snhu.edu,
  CS217 Assignment 6, Stack-Queue
*/

#include <iostream>
#include <stack>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::stack;

// prints 5 ints from the top of the stack, returns false if stack out of ints
bool printAndPop(stack<int> &stack)
{
  for (int i = 0; i < 5; i++)
  {
    if (stack.empty())
    {
      return false;
    }
    else
    {
      cout << stack.top() << " ";
      stack.pop();
    }
  }
  return true;
}

int main()
{
  stack<int> stack;
  queue<int> queue;

  int num = 1;
  while (num != 0)
  {
    cout << "Enter Number: ";
    cin >> num;
    queue.push(num);
  }

  while (!queue.empty())
  {

    // positive numbers
    if (queue.front() > 0)
    {
      stack.push(queue.front());
    }

    // negative numbers
    else if (queue.front() < 0)
    {
      if (!printAndPop(stack))
      {
        cout << "\nError: less than 5 numbers left\n";
        return 0;
      }
    }

    queue.pop();
  }

  return 0;
}