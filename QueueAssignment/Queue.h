#include<queue>
#include<iostream>
using std::queue;
using std::cin;
using std::cout;
using std::endl;

class MyQueue : public queue<int>
{
  public:
    void makeEmpty();
    int pop();
};