/*
* * Leetcode - 232
* * Implement Queue using Stacks
*/

#include <stack>
#include <iostream>

class MyQueue {
  public:
  std::stack<int> st; 

  MyQueue() {
  }

  void printQueue() {
    while(!st.empty()) {
      std::cout << st.top() << std::endl;
      st.pop();
    }
  }

  // * Pushes element x to the top of the stack.
  void push(int x) {
    // * push all the existing elements in temp stack
    std::stack<int> temp;
    while (!st.empty()) {
      temp.push(st.top());
      st.pop();
    }

    // * push new element at bottom of stack (i.e., last in queue)
    st.push(x);

    // * put all the temp elements into stack back
    while (!temp.empty()) {
      st.push(temp.top());
      temp.pop();
    }
  }

  // * Removes the element on the top of the stack and returns it.
  int pop() {
    int topElement = st.top();
    st.pop();
    return topElement;
  }
  
  // * Returns the element on the top of the stack.
  int peek() {
    return st.top();
  }

  // *  Returns true if the stack is empty, false otherwise.
  bool empty() {
    return st.size() == 0;
  }
};

int main() {
  MyQueue *q = new MyQueue();
  q->push(1);
  q->push(2);
  q->push(3);

  // q->printQueue();

  std::cout << "Queue Front: " << q->peek() << std::endl;
  q->pop();
  std::cout << "Queue Front: " << q->peek() << std::endl;
  q->pop();
  std::cout << "Queue Front: " << q->peek() << std::endl;
  q->pop();
  std::cout << "Queue Empty: " << q->empty() << std::endl;
}

// * Run the code
// * g++ --std=c++20 16-queue-using-stack.cpp -o output && ./output