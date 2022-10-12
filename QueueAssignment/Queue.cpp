#include "Queue.h"

void MyQueue::makeEmpty() {
  while(!empty()) {
    pop();
  }
}