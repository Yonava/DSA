#include "Queue.h"

int main() {

  MyQueue queue = MyQueue();
  
  int num = 1;
  while (num != 0) {
    cout << "Enter Number: ";
    cin >> num;
    if (num != 0) queue.push(num);
  }

  cout << queue.pop() << endl;
  cout << "Size of Queue: " << queue.size() << endl;
  queue.makeEmpty();
  cout << "Size of Queue: " << queue.size() << endl;


  return 0;
}