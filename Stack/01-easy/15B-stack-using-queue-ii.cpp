/*
* * Leetcode - 225
* * Implement Stack using Queues
* * Using only one stack
*/

#include <queue>
#include <iostream>

class MyStack {
  public:
  std::queue<int> que;

  MyStack() {
  }

  void printStack() {
    while (que.size()) {
      int topElement = que.front();
      std::cout << topElement << std::endl;
      que.pop();
    } 
  }

  // * Pushes element x to the top of the stack.
  void push(int x) {
    que.push(x);

    // * Push the elements from front to back
    for (int i = 0; i < que.size() - 1; ++i) {
      que.push(que.front());
      que.pop();
    }
  }

  // * Removes the element on the top of the stack and returns it.
  int pop() {
    int topElement = que.front();
    que.pop();
    return topElement;
  }
  
  // * Returns the element on the top of the stack.
  int top() {
    return que.front();
  }

  // *  Returns true if the stack is empty, false otherwise.
  bool empty() {
    return que.size() == 0;
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
// * g++ --std=c++20 15B-stack-using-queue-ii.cpp -o output && ./output