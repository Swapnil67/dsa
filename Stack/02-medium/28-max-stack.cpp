/*
 * Max Stack
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

 * MaxStack() initializes the stack object.
 * void push(int val) pushes the element val onto the stack.
 * void pop() removes the element on the top of the stack.
 * int top() gets the top element of the stack.
 * int getMax() retrieves the minimum element in the stack.
 * 
 * You must implement a solution with O(1) time complexity for each function.
 * 
 * https://www.geeksforgeeks.org/problems/get-max-from-stack/1
*/

#include <stack>
#include <vector>
#include <climits>
#include <iostream>

// * Using stack with pair of {num, max_element}
class MaxStackBrute {
  public: 
    // * {cur_num, max_ele}
    std::stack<std::pair<int, int>> st;
    MaxStackBrute() {
    }

    void push(int val) {
      if (st.empty()) {
        st.push({val, val});
      } else {
        int last_max = st.top().second;
        st.push({val, std::max(val, last_max)});
      }
    }
    
    void pop() {
      if (st.empty()) 
        return;

      return st.pop();
    }
    
    int top() {
      if (st.empty())
        return 0;
      return st.top().first;
    }
    
    int getMax() {
      return st.top().second;
    }
    
    int isEmpty() {
      return st.empty();
    }
};

// * Using Vector as stack
class MaxStack {
  public: 
    int s_top;
    int last_max;
    std::vector<int> stack;
    MaxStack() {
      s_top = -1;
      last_max = INT_MIN;
      stack.resize(10000);
    }

    void push(int val) {
      s_top += 1;
      stack[s_top] = val;
      if (val > last_max)
        last_max = val;
    }
    
    void pop() {
      if (s_top < 0)
        return;

      // * Check if last_max changed
      if (top() == last_max) {
        // * find new last_max
        last_max = INT_MAX;
        for(int i = 0; i <= s_top - 1; ++i) {
          last_max = std::max(last_max, stack[i]);
        }
      }

      s_top -= 1;
    }
    
    int top() {
      return s_top == -1 ? 0 : stack[s_top];
    }
    
    int getMax() {
      return last_max;
    }
};

int main() {
  MaxStack *stack = new MaxStack();
  stack->push(2147483646);
  stack->push(2147483646);
  stack->push(2147483647);
  std::cout << "top " << stack->top() << std::endl;
  stack->pop();
  std::cout << "max_stack " << stack->getMax() << std::endl;
  stack->pop();
  std::cout << "max_stack " << stack->getMax() << std::endl;
  stack->pop();
  stack->push(2147483647);
  std::cout << "top " << stack->top() << std::endl;
  std::cout << "max_stack " << stack->getMax() << std::endl;
  stack->push(-2147483648);
  std::cout << "top " << stack->top() << std::endl;
  std::cout << "max_stack " << stack->getMax() << std::endl;
  stack->pop();
  std::cout << "max_stack " << stack->getMax() << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 28-max-stack.cpp -o output && ./output