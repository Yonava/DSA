#include "Queue.h"

void MyQueue::makeEmpty() {
  while(!empty()) {
    queue::pop();
  }
}

int MyQueue::pop() {
  int output = front();
  queue::pop();
  return output;
}