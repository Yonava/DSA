#include "Queue.h"

int main() {

  MyQueue queue = MyQueue();
  int num = 1;
  while (num != 0) {
    cout << "Enter Number: ";
    cin >> num;
    queue.push(num);
  }

  cout << queue.size() << endl;
  queue.makeEmpty();
  cout << queue.size() << endl;


  return 0;
}