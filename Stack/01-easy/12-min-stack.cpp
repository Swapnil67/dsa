/*
* Min Stack
* Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
  * MinStack() initializes the stack object.
  * void push(int val) pushes the element val onto the stack.
  * void pop() removes the element on the top of the stack.
  * int top() gets the top element of the stack.
  * int getMin() retrieves the minimum element in the stack.
  * 
* https://leetcode.com/problems/min-stack/
* You must implement a solution with O(1) time complexity for each function.
*/

#include<vector>
#include<climits>
#include<iostream>

class MinStack {
  public: 
    int s_top;
    int last_min;
    std::vector<int> stack;
    MinStack() {
      this->s_top = -1;
      this->last_min = INT_MAX;
      this->stack.resize(10000);
    }

    void push(int val) {
      this->s_top += 1;
      this->stack[this->s_top] = (val);
      if (val <= this->last_min)
        this->last_min = val;
    }
    
    void pop() {
      if (this->s_top < 0)
        return;

      // * Check if last_min changed
      if (this->top() == this->last_min) {
        // * find new last_min
        this->last_min = INT_MAX;
        for(int i = 0; i <= this->s_top - 1; ++i) {
          this->last_min = std::min(this->last_min, this->stack[i]);
        }
      }
      this->s_top -= 1;
    }
    
    int top() {
      if(this->s_top == -1) {
        return 0;
      }
      return this->stack[this->s_top];
    }
    
    int getMin() {
      return this->last_min;
    }
};

// * Intuition
// *         t
// * 1 2 3 4 5

int main() {
  MinStack *stack = new MinStack();
  stack->push(2147483646);
  stack->push(2147483646);
  stack->push(2147483647);
  std::cout << "top " << stack->top() << std::endl;
  stack->pop();
  std::cout << "min_stack " << stack->getMin() << std::endl;
  stack->pop();
  std::cout << "min_stack " << stack->getMin() << std::endl;
  stack->pop();
  stack->push(2147483647);
  std::cout << "top " << stack->top() << std::endl;
  std::cout << "min_stack " << stack->getMin() << std::endl;
  stack->push(-2147483648);
  std::cout << "top " << stack->top() << std::endl;
  std::cout << "min_stack " << stack->getMin() << std::endl;
  stack->pop();
  std::cout << "min_stack " << stack->getMin() << std::endl;
  return 0;
}

// * Run the code
// * $CXX 12-min-stack.cpp -o output && ./output