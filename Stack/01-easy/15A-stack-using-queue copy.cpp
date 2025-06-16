/*
* * Leetcode - 225
* * Implement Stack using Queues
* * Using only two stack
*/

#include <queue>
#include <iostream>

class MyStack {
  public:
  std::queue<int> que1;
  std::queue<int> que2;

  MyStack() {
  }

  void printStack() {
    while (que1.size()) {
      int topElement = que1.front();
      std::cout << topElement << std::endl;
      que1.pop();
    } 
  }

  // * Pushes element x to the top of the stack.
  void push(int x) {
    que2.push(x);

    // * Push the prev elements
    while (!que1.empty()) {
      que2.push(que1.front());
      que1.pop();
    }

    // * put all the que2 elements into que1
    while (!que2.empty()) {
      que1.push(que2.front());
      que2.pop();
    }
  }

  // * Removes the element on the top of the stack and returns it.
  int pop() {
    int topElement = que1.front();
    que1.pop();
    return topElement;
  }
  
  // * Returns the element on the top of the stack.
  int top() {
    return que1.front();
  }

  // *  Returns true if the stack is empty, false otherwise.
  bool empty() {
    return que1.size() == 0;
  }
};

int main() {
  MyStack *st = new MyStack();
  st->push(1);
  st->push(2);
  st->push(3);
  // st->printStack();
  std::cout << "Stack Top: " << st->top() << std::endl;
  st->pop();
  std::cout << "Stack Top: " << st->top() << std::endl;
  st->pop();
  std::cout << "Stack Top: " << st->top() << std::endl;
  st->pop();
  std::cout << "Stack Empty: " << st->empty() << std::endl;
}

// * Run the code
// * g++ --std=c++20 15A-stack-using-queue.cpp -o output && ./output