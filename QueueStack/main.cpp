#include <iostream>
#include <stack>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::queue;

bool printAndPop(stack <int> &s) {
  for (int i = 0; i < 5; i++) {
    if (s.empty()) {
      return false;
    } else {
      cout << s.top() << " ";
      s.pop();
    }
  }
  return true;
}

int main() {
  stack <int> s;
  queue <int> q;

  int num = 1;
  while (num != 0) {
    cout << "Enter Number: ";
    cin >> num;
    q.push(num);
  }

  while (!q.empty()) {

    // positive numbers
    if (q.front() > 0) {
      s.push(q.front());
    }

    // negative numbers
    else if (q.front() < 0) {
      if (!printAndPop(s)) {
        cout << "\nError: less than 5 numbers left\n";
        return 0;
      }
    }

    q.pop();
  }

  return 0;
}